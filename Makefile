MARKDOWN_FILES=$(patsubst %/README.md, %/slides.html, $(shell find . -name "README.md" -not -path "./README.md" -not -path "./bin/README.md"))
DIAGRAM_FILES=$(addsuffix .lock, $(shell find . -name diagrams))

SLIDES=bin/slides.sh
DIAGRAMS=bin/diagrams.sh

all: $(MARKDOWN_FILES) $(DIAGRAM_FILES) .lock

.lock: $(MARKDOWN_FILES) $(DIAGRAM_FILES)
	touch $@
	browserrefresh

$(MARKDOWN_FILES): %slides.html : %README.md $(SLIDES)
	$(SLIDES) $< $@

$(DIAGRAM_FILES): %.lock : % $(DIAGRAMS)
	$(DIAGRAMS) $<
	touch $@

clean:
	rm $(DIAGRAM_FILES)
