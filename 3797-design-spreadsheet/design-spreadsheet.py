class Spreadsheet:

    def __init__(self, rows: int):
        self.rows=rows
        self.columns=26
        self.map={}

    def parse_cell(self,cell:str):
        column=ord(cell[0])-ord("A")
        row=int(cell[1:]) - 1
        return (column,row)

    def setCell(self, cell: str, value: int) -> None:
        r,c=self.parse_cell(cell)
        self.map[(r,c)]=value

    def resetCell(self, cell: str) -> None:
        r,c=self.parse_cell(cell)
        if (r,c) in self.map:
            del self.map[(r,c)] 

    def getValue(self, formula: str) -> int:
        if not formula.startswith("="):
            return int(formula)
        
        parts=formula[1:].split("+")
        total=0
        for part in parts :
            part=part.strip()
            if part[0].isalpha():
                r,c=self.parse_cell(part)
                total+=self.map.get((r,c),0)
            else:
                total+=int(part)
        return total

