#16.12 XML Encoding
Since XML is very verbose, you are given a way of encoding it where each tag gets mapped to a pre-defined integer value. The language/grammar is as follows.

    Element     --> @TAG attributes @END Children @END
    Attribute   --> @TAG Value
    END         --> 0
    @TAG        --> 'predifined map to integer'
    Value       --> string value

## C++
_Should use a library ? or should use self defined xml node ?_
I will outline only the key factors

_#690_
_#700_
_#715_
_#722_
_#740_
_#747_