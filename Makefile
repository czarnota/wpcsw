MARKDOWN_FILES=$(patsubst %/README.md, %/index.html, $(shell find . -name "README.md"))
DIAGRAM_FILES=$(addsuffix .lock, $(shell find . -name diagrams))

SLIDES=bin/slides.sh
DIAGRAMS=bin/diagrams.sh

all: $(MARKDOWN_FILES) $(DIAGRAM_FILES)

.lock: $(MARKDOWN_FILES) $(DIAGRAM_FILES)
	touch $@
	browserrefresh firefox

$(MARKDOWN_FILES): %index.html : %README.md $(SLIDES)
	$(SLIDES) $< > $@

$(DIAGRAM_FILES): %.lock : % $(DIAGRAMS)
	$(DIAGRAMS) $<
	touch $@

clean:
	rm $(DIAGRAM_FILES)
