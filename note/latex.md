## default code:
```
\documentclass{article}
\usepackage{amssymb}
\usepackage{amsmath}
\usepackage{breqn}
\newcommand{\limi}{\lim_{n\to\infty}}
\begin{document}

\end{document}
```

## list of some common syntax used in LaTeX:

1. Document Structure:
   - `\documentclass{}`: Specifies the document class.
   - `\begin{document}` and `\end{document}`: Marks the beginning and end of the document content.

2. Text Formatting:
   - `\textbf{}`: Formats text in bold.
   - `\textit{}`: Formats text in italics.
   - `\underline{}`: Underlines text.
   - `\textsuperscript{}`: Formats text as superscript.
   - `\textsubscript{}`: Formats text as subscript.

3. Sections and Headings:
   - `\section{}`: Creates a section heading.
   - `\subsection{}`: Creates a subsection heading.
   - `\subsubsection{}`: Creates a subsubsection heading.

4. Math Mode:
   - `$...$`: Puts content in inline math mode.
   - `\[...\]`: Puts content in display math mode.
   - `\(...\)`: Alternative syntax for inline math mode.

5. Equations and Mathematical Symbols:
   - `^`: Superscript.
   - `_`: Subscript.
   - `\frac{}{}`: Creates a fraction.
   - `\sqrt{}`: Square root.
   - `\sum`: Summation symbol.
   - `\int`: Integral symbol.

6. Environments:
   - `itemize` and `enumerate`: Creates bulleted or numbered lists.
   - `table` and `tabular`: Constructs tables.
   - `figure` and `includegraphics`: Inserts figures or images.
   - `equation`: same function as  `\[\]` and number the equation.
   - `align`: align equations to right. Adding `&` to align every line to where `&` is placed.
   - `dmath`: `breqn` package excludsive. It provides automatic line breaking and formatting for long mathematical equations.
   - `split`: 

7. Cross-Referencing:
   - `\label{}`: Assigns a label to a section, equation, or figure.
   - `\ref{}`: References a labeled section, equation, or figure.



8. Packages:
   - `\usepackage{}`: Loads additional LaTeX packages.

9. Comments:
   - `%`: Begins a comment. Anything after `%` on the same line is ignored.
   - `iffalse` and `fi`: Comment a bunch of word.

10. etc:
   - `\newcommand`: Define a new command or macro.

## vector and matrix
The `amsmath` package in LaTeX provides several useful functions and environments for vectors and matrices. Here are some of the key features related to vectors and matrices provided by `amsmath`:

1. Vectors:
   - `\vec{}`: Produces a vector arrow notation over a single character, e.g., `\vec{v}` for vector v.
   - `\boldsymbol{}`: Renders a bold version of a symbol, often used for vectors.
   - `\mathbf{}`: Formats text as bold, commonly used for vectors.
   - `\mathbf{v}`: Renders vector v in bold.

2. Matrices:
   - `bmatrix`: Creates a matrix with square brackets, suitable for representing matrices or vectors.
   - `pmatrix`: Creates a matrix with parentheses.
   - `vmatrix`: Creates a matrix with vertical bars.
   - `Vmatrix`: Creates a matrix with double vertical bars.
   
   These matrix environments can be used to represent matrices with elements arranged in rows and columns.

3. Row and Column Vectors:
   - `array`: Allows you to create custom arrays with specified column alignments, used for both row and column vectors.
   - `array` can be nested within matrix environments to create more complex structures.

