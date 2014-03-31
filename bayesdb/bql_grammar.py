#
#   Copyright (c) 2010-2014, MIT Probabilistic Computing Project
#
#   Lead Developers: Jay Baxter and Dan Lovell
#   Authors: Jay Baxter, Dan Lovell, Baxter Eaves, Vikash Mansinghka
#   Research Leads: Vikash Mansinghka, Patrick Shafto
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#

from pyparsing import *

## basica literals
operation_literal = oneOf("<= >= = < >")
equal_literal = Literal("=")
and_literal = CaselessLiteral("and")
from_literal = CaselessLiteral("from")
for_literal = CaselessLiteral("for")
into_literal = CaselessLiteral("into")
of_literal = CaselessLiteral("of")

## Many basic literals will never be used alone
## creating them separately like this allows for simpler whitespace and case flexibility
create_literal = CaselessLiteral("create")
btable_literal = CaselessLiteral("btable")
execute_literal = CaselessLiteral("execute")
file_literal = CaselessLiteral("file")
initialize_literal = CaselessLiteral("initialize")

## Composite literals: Inseparable elements that can have whitespace


## Values
#file_name = Word()

## Functions



## Clauses

