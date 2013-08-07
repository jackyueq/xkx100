/* Program      : /feature/me.c 
 * Author       :Kenny@Eternal.Civilization (3/25/1998) 
 * 
 * port to chinese wizard group : /feature/vi.c by ken@chinesemud.net (99-3-15) 
 */ 
 
#include <ansi.h>                       // ���� ANSI/VT100 �ն˻��������� 
 
#define ECHO 0                          // ��ȡ����ʱҪ��ʾ��Ԫ 
#define HIDE 1                          // ��ȡ����ʱ����ʾ��Ԫ 
#define REFRESH 1                       // ��ȡ������Ҫ�ػ滭�� 
#define LOGFILE "static/VI"             // �����춯��¼�� 
 
void start_edit(string filename);       // ���б༭������ʼ�༭ 
private void _append(object pl);        // ���α�������� 
private void _append_line(object pl);   // ���α���¼�һ���� 
private void _backspace(object pl);     // ɾ���α�ǰ���� 
protected void _confirm_save(string str, object pl); // �뿪�༭��ǰȷ�ϴ浵 
private void _del_char(object pl, int bs);      // ɾ���α��ϵ��� 
private void _del_line(object pl);              // ɾ������ 
private int  _dispatcher(object pl);            // ����ָ���ͬ��ʽ 
private void _down(object pl);                  // �α�������һ�� 
private void _end(object pl);                   // ���α��Ƶ���β 
private void _esc(object pl);                   // ������ģʽ�ص�����ģʽ 
private void _file_end(object pl);              // ���α��Ƶ���β 
private void _file_head(object pl);             // ���α��Ƶ���ͷ 
private void _goto_line(object pl);             // �����ض���ȥ 
protected void _goto_line_done(string str, object pl, int rein); // ȡ���к� 
private void _help(object pl);                  // �������� 
private void _home(object pl);                  // ���α��Ƶ����� 
protected void _input(string str, object pl, int fresh); // ���������ִ� 
private void _insert(object pl);                // ���α�ǰ����� 
private void _insert_line(object pl);           // ���α��Ϸ���һ���� 
private void _insert_exclam_mark(object pl);    // ���α�ǰ�����һ����!����Ԫ 
private void _join(object pl);                  // �����������Ƶ��������� 
private void _keymap(object pl);                // �����¹��ܼ� 
protected void _keymap_done(string str, object pl); // ȡ�ö��幦�ܼ� 
private void _left(object pl);                  // �α�������һ�� 
// ��״̬����ʾѶϢ 
private varargs void _message(object pl, string str, string callback, int hide, 
mixed arg); 
protected void _message_done(string str, object pl); // ����ѶϢ����ʾ 
private void _next_match(object pl);            // ��Ѱ/�滻�¸������ִ� 
private void _page_down(object pl);             // ���¾�һҳ��22 �У� 
private void _page_up(object pl);               // ���Ͼ�һҳ��22 �У� 
private void _process(object pl);               // ��������ģʽ���ִ����� 
protected void _quit(mixed unused, mixed pl);   // �뿪�༭�� 
private void _refresh(object pl);               // ���»��� 
private void _refresh_cursor(object pl);        // �����α�λ�� 
// �ػ滭�� 
private void _refresh_screen(object pl, int s_row, int e_row, int s_col); 
private void _refresh_status(object pl);        // ����״̬�� 
private void _replace(object pl);               // �ִ��滻 
protected void _replace_done(string str, object pl); // ȡ���滻�ִ� 
private void _right(object pl, int col, int extra);  // �α�������һ�� 
private void _search(object pl);                     // �ִ���Ѱ 
protected void _search_done(string str, object pl);  // ȡ����Ѱ�ִ� 
private void _tab(object pl);                        // ����ģʽ�� TAB ���Ķ�λ 
private void _undef_key(object pl);                  // ȡ��ĳ���ܼ����� 
protected void _undef_key_done(string str, object pl); // ȡ��ָ�����ܼ� 
private void _up(object pl);                           // �α�������һ�� 
private void _write(object pl);                        // ȡ�ô��浵������ 
protected void _write_done(string str, object pl, int quit); // ���浵�� 
 
private mapping EditedFiles=([ ]);              // �༭�еĵ��� 
/* 
int iS_Row, iE_Row,                             // �ɼ��Ӵ���ʼĩ�к� 
    iS_Col, iE_Col,                             // �ɼ��Ӵ���ʼδ��λ 
    iRow,   iCol,                               // �α�λ�� 
    is_Command_Mode, is_NewFile, is_Modify,     // ����״����� 
    is_Substituted;                             // ����������� 
string *sText,                                  // �������� 
       sChar, sOldChar,                         // �����ִ������ 
       sCount,                                  // ������� 
       sFileName,                               // �༭���� 
       sSearch, sReplace;                       // ��Ѱ/�滻�ִ� 
mapping keymap;                                 // ���ܼ�������ձ� 
*/ 
 
void start_edit(string file)                // ���б༭������ʼ�༭ 
{ 
        int  i; 
        mapping me; 
 
 
        if (objectp(EditedFiles[file])) 
        { 
                write(sprintf("%s ���ڱ༭������������Ժ��ٱ༭��\n", 
                        capitalize(EditedFiles[file]->query("id")))); 
                return; 
        } // if 
        this_player()->set_temp("me", ([ ])); 
        me = this_player()->query_temp("me"); 
        me["sFileName"] = file; 
        if (file_size(file) <= 0) 
        {        // ��������С� 1 
                me["sText"] = ({ "" }); 
                if (file_size(file) < 0) 
                {        // �µ� 
                        me["is_Command_Mode"] = 0; 
                        me["is_NewFile"] = 1; 
                } 
        } 
        else 
        { 
                string content=read_file(file), tabs="        "; 
 
                // �������ȴ�� 0 
                me["is_Command_Mode"] = 1; 
                me["is_NewFile"] = 0; 
                if (stringp(content)) 
                { 
                        me["sText"] = explode(read_file(file), "\n"); 
                        // �� TAB���� 8 ���հ״��棬�Է����α�λ�õļ��� 
                        for (i=sizeof(me["sText"])-1; i>=0; i--) 
                        { 
                                int len=sizeof(me["sText"][i]); 
                                reset_eval_cost(); 
                                for (int j=0; j<len; j++) 
                                        if (me["sText"][i][j] == '\t') 
                                                me["sText"][i] = replace_string( 
                                                        me["sText"][i], "\t", tabs[0..7-j%8]); 
                        } 
                } 
                else me["sText"] = ({ "" }); 
        } // old file 
 
        me["sCount"] = ""; 
        me["sSearch"] = me["sReplace"] = me["is_Modify"] = 0; 
        me["iE_Row"] = 23; 
        me["iS_Row"] = me["iS_Col"] = me["iRow"] = me["iCol"] = 1; 
        EditedFiles += ([ file: this_player()->link() ]); 
 
        // ȡ��/�趨���ܼ�������ձ� 
             if (!mapp(me["keymap"] = this_player()->query("me_keymap"))) 
                     me["keymap"] = ([ ]); 
        if (this_player()->query("me_no_help") || 
            this_player()->query_temp("no_me_help")) 
        {        // �ǵ�һ��ʹ�ñ༭����ֱ�ӽ���༭�� 
                _refresh_screen(this_player(), 1, 23, 1); 
 
                get_char("_input", HIDE, this_player()); 
        } 
        else 
        {        // ��һ��ʹ�ñ༭�����ȿ�����˵�� 
                this_player()->set_temp("no_me_help", 1); 
                _help(this_player()); 
        } 
} // start_edit() 
 
 
private void _refresh_cursor(object pl)        // �����α�λ�� 
{ 
        mapping me=pl->query_temp("me"); 
        printf(ESC "[%d;%df", me["iRow"]+1, me["iCol"]); 
} // _refresh_cursor() 
 
 
private void _refresh_status(object pl)        // ����״̬�� 
{ 
        mapping me=pl->query_temp("me"); 
 
        // �ƶ��α굽 (1,1)���÷�����Ԫ��ʾ״̬�� 
        printf(HOME + NOR + REV + "��:%4d ��:%3d %-43s %10s [����ģʽ]" + NOR, 
                me["iS_Row"]+me["iRow"]-1, me["iS_Col"]+me["iCol"]-1, 
                sprintf("%s %s", me["sFileName"], (me["is_Modify"]? "(���޸�)": 
                (me["is_NewFile"]? "(�µ�)": "")))[0..42], 
                (me["is_Command_Mode"]? "?:��������": "[����ģʽ]")); 
        _refresh_cursor(pl); 
} // _refresh_status() 
 
 
// �ػ滭�� 
private void _refresh_screen(object pl, int s_row, int e_row, int s_col) 
{ 
        int  i, temp; 
        mapping me=pl->query_temp("me"); 
 
 
        if (e_row < s_row)                // ���ʼĩ�кŵ�������� 
        { 
                temp = e_row; 
                e_row = s_row; 
                s_row = temp; 
        } 
 
        if (s_row < 1) s_row = 1; 
        if (s_col < 1) s_col = 1; 
        if (e_row > sizeof(me["sText"])) // ���ܳ�����β 
                e_row = sizeof(me["sText"]); 
        if (e_row-s_row > 22) e_row = s_row+22; 
 
        me["iS_Row"] = s_row;        me["iE_Row"] = e_row; 
        me["iS_Col"] = s_col;        me["iE_Col"] = s_col+79; 
 
        printf(REF+NOR);                // ������棬�ƶ��α굽 (1,1) 
        for (i=me["iS_Row"]-1; i<me["iE_Row"]; i++) 
                printf("\r\n%s", me["sText"][i][me["iS_Col"]-1..me["iE_Col"]-1]); 
        for (i=me["iS_Row"]+22-me["iE_Row"]; i>0; i--) 
                printf("\r\n~");        // �����к��� ~ ��ʾ 
        _refresh_status(pl); 
} // _refresh_screen() 
 
 
protected void _input(string str, object pl, int fresh) // ���������ִ� 
{ 
        int    i, size, bs=0; 
        string *chars; 
        mapping me=pl->query_temp("me"); 
 
        if (fresh) 
        {        // �ػ滭�� 
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]); 
                get_char("_input", HIDE, pl); 
                return; 
        } 
 
        me["is_Substituted"] = 1;       // ���趨����������� 
        if (str == "")                  // ������ Backspace/Ctrl-Backspace 
        { 
                str = "BACKSPACE"; 
                bs = 1; 
        } 
        if (str[0] == 27) 
        { 
                chars = explode(str, ESC);      // ��������ִ����� ESC �Ͽ� 
                for (i=sizeof(chars)-1; i>=0; i--) 
                        chars[i] = ESC + chars[i];      // �ӻ� ESC 
                if (sizeof(chars) == 0)                 // ��ֻ�ǵ�һ��Ԫ ESC 
                        chars = ({ ESC }); 
        } 
        else    chars = ({ str }); 
 
        size = sizeof(chars); 
        for (i=0; i<size; i++) 
        {        // ת��������Ϊ�༭������ 
                switch (chars[i]) 
                { 
                case "\t":       me["sChar"] = "TAB";   break; 
                case "\r":       me["sChar"] = "ENTER"; break; 
                case ESC:        me["sChar"] = "ESC";   break; 
                case ESC "OA": 
                case ESC "[A":   me["sChar"] = "UP";    break; 
                case ESC "OB": 
                case ESC "[B":   me["sChar"] = "DOWN";  break; 
                case ESC "OC": 
                case ESC "[C":   me["sChar"] = "RIGHT"; break; 
                case ESC "OD": 
                case ESC "[D":   me["sChar"] = "LEFT";  break; 
                case ESC "OH": 
                case ESC "[H": 
                case ESC "1~": 
                case ESC "[1~":  me["sChar"] = "HOME";  break; 
                case ESC "[2~":  me["sChar"] = "INSERT";break; 
                case ESC "[3~":  me["sChar"] = "DELETE";break; 
                case ESC "4~":   me["sChar"] = "END";   break; 
                case ESC "[4~":  me["sChar"] = "END";   break; 
                case ESC "[5~":  me["sChar"] = "PAGEUP";break; 
                case ESC "[6~":  me["sChar"] = "PAGEDOWN";break; 
                case ESC "OP":   me["sChar"] = "F1";    break; 
                case ESC "OQ":   me["sChar"] = "F2";    break; 
                case ESC "OR":   me["sChar"] = "F3";    break; 
                case ESC "OS":   me["sChar"] = "F4";    break; 
                case ESC "m":    me["sChar"] = "F5";    break; 
                case ESC "[17~": me["sChar"] = "F6";    break; 
                case ESC "[18~": me["sChar"] = "F7";    break; 
                case ESC "[19~": me["sChar"] = "F8";    break; 
                case ESC "[20~": me["sChar"] = "F9";    break; 
                case ESC "[21~": me["sChar"] = "F10";   break; 
                case ESC "[23~": me["sChar"] = "F11";   break; 
                case ESC "[24~": me["sChar"] = "F12";   break; 
                default: 
                        if (sizeof(chars[i])==1 && 
                            0<chars[i][0] && chars[i][0]<27) 
                                switch (chars[i][0]) 
                                { // �������룬ʹ������ģʽҲ��ʹ��ָ�� 
                                case  1: me["sChar"]="Ctrl-A"; break; 
                                case  2: me["sChar"]="Ctrl-B"; break; 
                                case  4: me["sChar"]="Ctrl-D"; break; 
                                case  6: me["sChar"]="Ctrl-F"; break; 
                                case  7: me["sChar"]="Ctrl-G"; break; 
                                case 10: me["sChar"]="Ctrl-J"; break; 
                                case 11: me["sChar"]="Ctrl-K"; break; 
                                case 12: me["sChar"]="Ctrl-L"; break; 
                                case 14: me["sChar"]="Ctrl-N"; break; 
                                case 15: me["sChar"]="Ctrl-O"; break; 
                                case 16: me["sChar"]="Ctrl-P"; break; 
                                case 17: me["sChar"]="Ctrl-Q"; break; 
                                case 18: me["sChar"]="Ctrl-R"; break; 
                                case 19: me["sChar"]="Ctrl-S"; break; 
                                case 20: me["sChar"]="Ctrl-T"; break; 
                                case 21: me["sChar"]="Ctrl-U"; break; 
                                case 22: me["sChar"]="Ctrl-V"; break; 
                                case 23: me["sChar"]="Ctrl-W"; break; 
                                case 24: me["sChar"]="Ctrl-X"; break; 
                                case 25: me["sChar"]="Ctrl-Y"; break; 
                                case 26: me["sChar"]="Ctrl-Z"; break; 
                        } // switch 
                        else 
                        { 
                                me["sChar"] = chars[i];            // ��Ϊ��ͨ�ִ� 
                                if (!bs) me["is_Substituted"] = 0; // ��������� 
                        } // else 
                } // switch 
                // ��ת������ִ��͵�����ָ�ʽ�������ȴ���ȡ�¸����� 
                if (_dispatcher(pl) && i==size-1) get_char("_input", HIDE, pl); 
        } // for 
} // input() 
 
 
private int _dispatcher(object pl)                // ����ָ���ͬ��ʽ 
{ 
        int  i, count=1; 
        mapping me=pl->query_temp("me"); 
 
 
        if ( me["is_Command_Mode"] || 
            (me["is_Substituted"] && // ������ģʽҲ��ʹ��ĳЩָ�� 
             // �����ָ����⴦�� 
             me["sChar"]!="ENTER" && me["sChar"]!="TAB") ) 
        {        // ����������ģʽ 
                if (sizeof(me["sChar"])!=1 && !me["is_Substituted"]) 
                        return 1; 
                // ��鹦�ܼ�������ձ����¶������� 
                if (!undefinedp(me["keymap"][me["sChar"]])) 
                        me["sChar"] = 
                        me["keymap"][me["sChar"]]; 
                if (!stringp(me["sChar"])) return 1; // Type checking... 
                // ��������ֵĻ������Ǹ��ӵ���������� 
                if ('0'<=me["sChar"][0] && me["sChar"][0]<='9') 
                        me["sCount"] += me["sChar"]; 
                else 
                { 
                        sscanf(me["sCount"], "%d", count); 
                        me["sCount"] = ""; // ���������� 
                        // �ظ��ϸ�ָ�� 
                        if (me["sChar"] == ".") 
                                me["sChar"] = me["sOldChar"]; 
                        else        // ��¼��ε�ָ�� 
                                me["sOldChar"] = me["sChar"]; 
                } 
 
                for (i=0; i<count; i++) 
                        switch (me["sChar"]) // ����ָ���ͬ��ʽ 
                        { 
                        case "a":_append(pl);                           break; 
                        case "d": 
                        case "Ctrl-D": _del_line(pl);                  break; 
                        case "f": 
                        case "Ctrl-Z": _refresh(pl);                break; 
                        case "g": 
                        case "Ctrl-G": _goto_line(pl);                break; 
                        case "h": 
                        case "LEFT": 
                        case "Ctrl-J": _left(pl);                   break; 
                        case "i":      _insert(pl);                break; 
                        case "j": 
                        case "DOWN": 
                        case "Ctrl-K": _down(pl);                break; 
                        case "k": 
                        case "UP": 
                        case "Ctrl-O": _up(pl);                        break; 
                        case "l": 
                        case "RIGHT": 
                        case "Ctrl-L": _right(pl, 1, 
                                                (me["is_Command_Mode"]?0:1)); 
                                       break; 
                        case "m": _keymap(pl);                        break; 
                        case "n": 
                        case "Ctrl-N": _next_match(pl);                break; 
                        case "o": _append_line(pl);                    break; 
                        case "q":        // ��ʾ���ٶ�ȡ�����룬�����༭ 
                        case "F4": 
                        case "Ctrl-Q": _quit(0, pl);                return 0; 
                        case "r": 
                        case "Ctrl-R": _replace(pl);                break; 
                        case "s": 
                        case "Ctrl-S": _search(pl);                   break; 
                        case "u": _undef_key(pl);                break; 
                        case "w": 
                        case "F2": 
                        case "Ctrl-W": _write(pl);                      break; 
                        case "x": 
                        case "DELETE": 
                        case "Ctrl-X":   _del_char(pl, 0);        break; 
                        case "A": 
                        case "HOME": 
                        case "Ctrl-A":   _home(pl);        break; 
                        case "B": 
                        case "PAGEUP": 
                        case "Ctrl-B":   _page_up(pl);        break; 
                        case "E": 
                        case "END": 
                        case "Ctrl-E":   _end(pl);        break; 
                        case "F": 
                        case "PAGEDOWN": 
                        case "Ctrl-F":   _page_down(pl);        break; 
                        case "J": 
                        case "Ctrl-P": _join(pl);         break; 
                        case "O": _insert_line(pl);         break; 
                        case "U": 
                        case "Ctrl-U": _file_head(pl);        break; 
                        case "V": 
                        case "Ctrl-V": _file_end(pl);        break; 
                        case "?": 
                        case "F1": 
                        case "Ctrl-Y": _help(pl);         break; 
                        case "~": 
                        case "Ctrl-T": _insert_exclam_mark(pl);        break; 
                        case "BACKSPACE": _backspace(pl);          break; 
                        case "ESC": _esc(pl);                         break; 
                        case "TAB": _tab(pl);                        break; 
                        } // switch 
        } // if me["is_Command_Mode"] 
        else 
                _process(pl);                // ��������ģʽ���ִ����� 
 
        return 1;                        // ��ʾ������ȡ�����룬�����༭ 
} // dispatcher() 
 
 
private void _append(object pl)                // ���α�������� 
{ 
        mapping me=pl->query_temp("me"); 
 
        if (sizeof(me["sText"]) == 0) return; 
        me["is_Command_Mode"] = 0; 
        _refresh_status(pl); 
        _right(pl, 1, 1); 
} // _append() 
 
 
private void _append_line(object pl)        // ���α���¼�һ���� 
{ 
        string *text; 
        mapping me=pl->query_temp("me"); 
 
        me["is_Command_Mode"] = me["is_NewFile"] = 0; 
        me["is_Modify"] = 1; 
        text = me["sText"][0..me["iS_Row"]+me["iRow"]-2] + ({ "" }) + 
                me["sText"][me["iS_Row"]+me["iRow"]-1..<1]; 
        me["sText"] = text; 
        _refresh_screen(pl, me["iS_Row"], sizeof(me["sText"]), 1); 
        me["iCol"] = 1; 
        _down(pl); 
} // _append_line() 
 
 
private void _backspace(object pl)        // ɾ���α�ǰ���� 
{ 
        mapping me=pl->query_temp("me"); 
 
        if (me["iS_Col"] == me["iCol"])        return; 
        _left(pl); 
        _del_char(pl, 1); 
} // _backspace() 
 
 
protected void _confirm_save(string str, object pl) // �뿪�༭��ǰȷ�ϴ浵 
{ 
        mapping me=pl->query_temp("me"); 
 
        if (str=="y" || str=="Y") return _write_done("", pl, 1); 
        me["is_Modify"] = 0;                // �趨��δ�޸ġ���� 
        _quit(0, pl); 
} // _confirm_save() 
 
 
private void _del_char(object pl, int bs)                // ɾ���α��ϵ��� 
{ 
        int    go_left=0;                // �Ƿ���ɾ����Ҫ�����α� 
        string str; 
        mapping me=pl->query_temp("me"); 
 
 
        if (sizeof(me["sText"])==0 || 
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])==0) 
             return; 
        if (me["is_NewFile"] || !me["is_Modify"]) 
        { 
                me["is_NewFile"] = 0; 
                me["is_Modify"] = 1; 
                _refresh_status(pl); 
        } 
 
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]); 
                return; 
        str = me["sText"][me["iS_Row"]+me["iRow"]-2][0..me["iS_Col"]+me["iCol"]-3]; 
        // ����Ƿ���Ҫ����ʣ�µ����� 
        if (me["iS_Col"]+me["iCol"]-1 < 
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])) 
                str += me["sText"][me["iS_Row"]+ 
                me["iRow"]-2][me["iS_Col"]+me["iCol"]-1..<1]; 
        else        go_left = 1;                // ��Ϊ��ɾ����β���֣�����Ҫ��  
        me["sText"][me["iS_Row"]+me["iRow"]-2] = str; 
        printf(ESC "[%d;1f%-80s", me["iRow"]+1,        me["sText"][me["iS_Row"]+ 
                me["iRow"]-2][me["iS_Col"]-1..me["iE_Col"]-1]); 
        if (go_left && !bs) _left(pl); 
        else        _refresh_cursor(pl); 
} // _del_char() 
 
 
private void _del_line(object pl)        // ɾ������ 
{ 
        string *text=({ }); 
        mapping me=pl->query_temp("me"); 
        me["is_NewFile"] = 0; 
        me["is_Modify"] = 1; 
        if (me["iS_Row"]+me["iRow"]-2 > 0) 
                text = me["sText"][0..me["iS_Row"]+me["iRow"]-3]; 
        text += me["sText"][me["iS_Row"]+me["iRow"]-1..<1]; 
        me["sText"] = text; 
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]); 
        if (me["iS_Row"]+me["iRow"]-1 > sizeof(me["sText"])) 
                _up(pl);                // ����ɾ������һ�У���Ҫ�����α� 
        // ���α����λ�ó�����β�����ƶ��α굽��β 
        else if (me["iS_Col"]+me["iCol"]-1 > 
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])) 
            _end(pl); 
} // _del_line() 
 
 
private void _down(object pl)                // �α�������һ�� 
{ 
        int  acc; 
        mapping me=pl->query_temp("me"); 
 
 
        // ����Ƿ����ڵ�β 
        if (me["iS_Row"]+me["iRow"]-1 >= sizeof(me["sText"])) 
                // ������ʾ��β��һ�У������� 
                if (me["iRow"] < 23) return; 
                else 
                {        // �����ӵ�β��һ�У���ͻ�Ե�β�Ĵ��� 
                        me["iS_Row"]++; 
                        printf(ESC "[24;1f\r\n~"); 
                        me["iRow"] = 22; 
                } 
        else if (++me["iRow"] > 23) 
        {        // �����Ͼ���ʾ��һ�� 
                me["iS_Row"]++;                me["iE_Row"]++; 
                printf(ESC "[24;1f\r\n%s", me["sText"][me["iE_Row"]-1] 
                        [me["iS_Col"]-1..me["iE_Col"]-1]); 
                me["iRow"] = 23; 
        } 
 
        // ���α����λ�ó�����β�����ƶ��α굽��β 
        if (me["iS_Col"]+me["iCol"]-1 > 
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])) 
                me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])- 
                        me["iS_Col"]+(me["is_Command_Mode"]?1:2); 
        // ���������֣���λ�ڵ�һ�� 
        if (me["iCol"]==0 && me["iS_Col"]==1) me["iCol"] = 1; 
        if (me["iCol"] > 0)_refresh_status(pl); 
        else 
        {        // �α����λ����ԭ�����⣬��Ҫ�ػ滭�� 
                acc = me["iCol"];        me["iCol"] = 1; 
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 
                        me["iS_Col"]+acc-1); 
        } 
} // _down() 
 
 
private void _end(object pl)                // ���α��Ƶ���β 
{ 
        mapping me=pl->query_temp("me"); 
 
        if (sizeof(me["sText"]) == 0) return; 
        // ������β��λ�� 
        me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])- 
                me["iS_Col"]+(me["is_Command_Mode"]?1:2); 
        if (me["iCol"] == 0) me["iCol"] = 1; // ���������֣���λ�ڵ�һ�� 
        if (sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]) < me["iE_Col"]) 
                    _refresh_status(pl); 
        else 
        {        // �α����λ����ԭ�����⣬��Ҫ�ػ滭�� 
                me["iCol"] = 79; 
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]+ 
                        (sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])- 
                        me["iE_Col"]+1)); 
        } 
} // _end() 
 
 
private void _esc(object pl)                // ������ģʽ�ص�����ģʽ 
{ 
        mapping me=pl->query_temp("me"); 
        me["is_Command_Mode"] = 1; 
        _left(pl); 
} // _esc() 
 
 
private void _file_end(object pl)        // ���α��Ƶ���β 
{ 
        mapping me=pl->query_temp("me"); 
        if (sizeof(me["sText"]) == 0) return; 
        _goto_line_done(sprintf("%d", sizeof(me["sText"])), pl, 0); 
} // _file_end() 
 
 
private void _file_head(object pl)        // ���α��Ƶ���ͷ 
{ 
        mapping me=pl->query_temp("me"); 
        if (sizeof(me["sText"]) == 0) return; 
        _goto_line_done("1", pl, 0); 
} // _file_head() 
 
 
private void _goto_line(object pl)        // �����ض���ȥ 
{ 
        mapping me=pl->query_temp("me"); 
        _message(pl, sprintf("�������кţ�ֱ�Ӱ� ENTER ȡ����1~%d)��", 
                sizeof(me["sText"])), "_goto_line_done", ECHO, 1); 
} // _goto_line() 
 
 
protected void _goto_line_done(string str, object pl, int rein) // ȡ���к� 
{ 
        int        no; 
        mapping me=pl->query_temp("me"); 
 
        if (str == "") return _message_done("", pl); 
        if (sscanf(str, "%d", no)!=1 || no<1 || no>sizeof(me["sText"])) 
                return _message(pl, "������кţ�", "_message_done", HIDE); 
 
        me["iCol"] = 1; 
        if (me["iS_Row"]<=no && no<=me["iE_Row"]) 
        {        // ָ���к���ԭ���ӷ�Χ�� 
                me["iRow"] = no-me["iS_Row"]+1; 
                _refresh_status(pl); 
        } 
        else 
        {        // ָ���кŲ���ԭ���ӷ�Χ�У���Ҫ�ػ滭�� 
                me["iS_Row"] = no-11; 
                if (me["iS_Row"] < 1)        me["iS_Row"] = 1; 
                if (me["iE_Row"] < no+11)        me["iE_Row"] = no+11; 
                me["iRow"] = no-me["iS_Row"]+1; 
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 1); 
        } 
        if (rein) get_char("_input", HIDE, pl); // ����Ƿ���Ҫ��ȡ�´����� 
} // _goto_line_done() 
 
 
private void _help(object pl)                // �������� 
{ 
        printf(REF + 
"         �� LPMud ȫөĻ�༭�� ��1.3 �� 3/25/1998   ��Ȩ����.\r 
\r 
 a            ���α��������          d  Ctrl-D    ɾ������\r 
 f  Ctrl-Z    ���»���                g  Ctrl-G    �����ض���ȥ\r 
 h  Ctrl-J    �α�������һ��          i            ���α�ǰ�����\r 
 j  Ctrl-K    �α�������һ��          k  Ctrl-O    �α�������һ��\r 
 l  Ctrl-L    �α�������һ��          m            �����¹��ܼ�\r 
 n  Ctrl-N    ��Ѱ/�滻�¸������ִ�   o            ���α���¼�һ����\r 
 q  Ctrl-Q    �뿪�༭��              r  Ctrl-R    �ִ��滻\r 
 s  Ctrl-S    �ִ���Ѱ                u            ȡ��ĳ���ܼ�����\r 
 w  Ctrl-W    ���浵��                x  Ctrl-X    ɾ���α��ϵ���\r 
 A  Ctrl-A    ���α��Ƶ�����          B  Ctrl-B    ���Ͼ�һҳ��22 �У�\r 
 E  Ctrl-E    ���α��Ƶ���β          F  Ctrl-F    ���¾�һҳ��22 �У�\r 
 J  Ctrl-P    ���������ֽӵ���������  O            ���α��Ϸ���һ����\r 
 U  Ctrl-U    ���α��Ƶ���ͷ          V  Ctrl-V    ���α��Ƶ���β\r\n"); 
        printf( 
" .            �ظ��ϸ�ָ��            ?  Ctrl-Y    �������棨�˻��棩\r 
 ~   Ctrl-T    ���α�ǰ�����һ����!����Ԫ\r\n 
 �Ϸ��Ķ��������ĸ�� ESC��F1��F12��BACKSPACE��TAB��ENTER��INSERT��DELETE��\r 
 HOME��END��PAGEUP��PAGEDOWN��UP��DOWN��LEFT��RIGHT��Ctrl-A��Ctrl-Z��\r 
\r 
 ��ӭ�����˱༭�������뱣����Ȩ���棬���κ�����ͽ����������ң�\r 
 kenny@cindy.cis.nctu.edu.tw��\r 
                                                  [��������ص��༭��]" 
); 
        get_char("_input", HIDE, pl, REFRESH); // ��ȡ�������ػ滭�� 
} // _help() 
 
 
private void _home(object pl)                // ���α��Ƶ����� 
{ 
        mapping me=pl->query_temp("me"); 
 
        me["iCol"] = 1; 
        if (me["iS_Col"] == 1)_refresh_status(pl); 
        else        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 1); 
} // _home() 
 
 
private void _insert(object pl)                // ���α�ǰ����� 
{ 
        mapping me=pl->query_temp("me"); 
 
        if (sizeof(me["sText"]) == 0) return; 
        me["is_Command_Mode"] = 0; 
        _refresh_status(pl); 
} // _insert() 
 
 
private void _insert_line(object pl)        // ���α��Ϸ���һ���� 
{ 
        string *text=({ }); 
        mapping me=pl->query_temp("me"); 
 
        me["is_Command_Mode"] = me["is_NewFile"] = 0; 
        me["is_Modify"] = 1; 
        // ����Ƿ��α��Ϸ��Ƿ������� 
        if (me["iS_Row"]+me["iRow"]-3 >= 0) 
                text = me["sText"][0..me["iS_Row"]+me["iRow"]-3]; 
        text += ({ "" }); 
        text += me["sText"][me["iS_Row"]+me["iRow"]-2..<1]; 
        me["sText"] = text; 
        me["iCol"] = 1; 
        _refresh_screen(pl, me["iS_Row"], sizeof(me["sText"]), 1); 
} // _insert_line() 
 
 
private void _insert_exclam_mark(object pl) // ���α�ǰ�����һ����!����Ԫ 
{ 
        mapping me=pl->query_temp("me"); 
 
        // ��Ϊ�޷��������롸!���������صؼӴ˺�ʽ�����롸!���� 
        if (sizeof(me["sText"]) == 0) return; 
        me["sChar"] = "!"; 
        _process(pl); 
} // _insert_!() 
 
 
private void _join(object pl)                // �����������Ƶ��������� 
{ 
        string *text=({ }); 
        mapping me=pl->query_temp("me"); 
 
 
        if (me["iS_Row"]+me["iRow"]-1 >= sizeof(me["sText"])) return; 
 
        me["is_NewFile"] = 0; 
        me["is_Modify"] = 1; 
        _end(pl);                        // �Ƚ��α��Ƶ���β 
        text = me["sText"][0..me["iS_Row"]+me["iRow"]-2]; 
        if (sizeof(me["sText"][me["iS_Row"]+me["iRow"]-1])) 
        {        // �����������ݸ������� 
                text[me["iS_Row"]+me["iRow"]-2] += (" "+ 
                        me["sText"][me["iS_Row"]+me["iRow"]-1]); 
                _right(pl, 1, 1); 
        } 
        text += me["sText"][me["iS_Row"]+me["iRow"]..<1]; 
        me["sText"] = text; 
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]); 
} // _join() 
 
 
private void _keymap(object pl)                // �����¹��ܼ� 
{ 
        _message(pl, "�������¶������ԭ��\�ܼ���ֱ�Ӱ� ENTER ȡ�����Կհ׸�����", 
                "_keymap_done", ECHO); 
} // _keymap() 
 
 
protected void _keymap_done(string str, object pl) // ȡ�ö��幦�ܼ� 
{ 
        string old, _new; 
        mapping me=pl->query_temp("me"); 
 
        _refresh_status(pl); 
        if (str != "") 
        {        // ������������ 
                if (sscanf(str, "%s %s", _new, old) != 2) 
                        return _message(pl, "�����ʽ����", "_message_done", 
                                HIDE); 
                me["keymap"][_new] = old; 
                _message(pl, sprintf("���ˣ��Ӵ������¶������%s������ԭ��\�ܼ�? 
?s���Ĺ�\���ˣ�", 
                        _new, old), "_message_done", HIDE); 
        } 
        else        get_char("_input", HIDE, pl); // ȡ�����룬������ȡ�¸����� 
} // _keymap_done() 
 
 
private void _left(object pl)                // �α�������һ�� 
{ 
        mapping me=pl->query_temp("me"); 
 
        if (me["iS_Col"]==1 && me["iCol"]==1) return _refresh_status(pl); 
        if (--me["iCol"] < 1) 
        {        // �α����λ����ԭ�����⣬��Ҫ�ػ滭�� 
                // ������ 8 ��̫��Ļ�����ֻ����һ�� 
                if (me["iS_Col"]-8 < 1) 
                        me["iCol"] = me["iS_Col"]-1; 
                else        me["iCol"] = 8; // ��Ȼ���趨�α��ڵ� 8 ��λ�� 
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 
                        me["iS_Col"]-me["iCol"]); 
                return; 
        } 
        _refresh_status(pl); 
} // _left() 
 
 
// ��״̬����ʾѶϢ 
private varargs void _message(object pl, string str, string callback, int hide, 
mixed arg) 
{ 
        printf(HOME + NOR + REV);        // �ƶ��α굽 (1,1)���趨������Ԫ��ʾ 
        // ���ԭ״̬�е�ѶϢ 
        printf(" 
                "); 
        printf(HOME + str);                // �ƶ��α굽 (1,1)������ʾѶϢ 
        input_to(callback, hide, pl, arg); // ��ȡ�������� 
} // _message() 
 
 
protected void _message_done(string str, object pl) // ����ѶϢ����ʾ 
{ 
        _refresh_status(pl); 
        get_char("_input", HIDE, pl);        // ������ȡ�����ִ� 
} // _message_done() 
 
 
private void _next_match(object pl)                // ��Ѱ/�滻�¸������ִ� 
{ 
        mapping me=pl->query_temp("me"); 
        string str=""; 
        // �趨��ʼ��Ѱλ��Ϊ�α�����λ�� 
        int    j=me["iS_Col"]+me["iCol"]-1, 
               i, ofs; 
 
 
        if (!stringp(me["sSearch"])) return; // ��û���趨��Ѱ�ִ��������� 
 
        for (i=me["iS_Row"]+me["iRow"]-2; i<sizeof(me["sText"]); i++) 
        { 
                if ((ofs = strsrch(me["sText"][i][j-1..<1], me["sSearch"]))== -1) 
                        j = 1; // ����û�ҵ��Ļ����趨���дӵ�һ����ʼ�� 
                else 
                {        // �ҵ�ָ���ִ���, �ƶ��α굽Ŀ���� 
                        _goto_line_done(sprintf("%d", i+1), pl, 0); 
                        me["iCol"] = j+ofs; // ����ָ���ִ��ľ���λ�� 
                        // ��ָ���ִ�����ԭ�����⣬���ػ滭�� 
                        if (me["iCol"]<me["iS_Col"] || 
                            me["iCol"]+strlen(me["sSearch"])>me["iS_Col"]+79) 
                                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 
                                        me["iCol"]); 
                        if (stringp(me["sReplace"])) 
                        {        // ��Ҫ�滻�ִ� 
                                me["is_NewFile"] = 0; 
                                me["is_Modify"] = 1; 
                                // �����α�ǰ���� 
                                str = me["sText"][i][0..me["iCol"]-2]; 
                                str += me["sReplace"]; 
                                str += (me["sText"][i][me["iCol"]+ 
                                        strlen(me["sSearch"])-1..<1]); 
                                me["sText"][i] = str; 
                                // ���滻�ִ�����ԭ�����⣬���ػ滭�� 
                                if (me["iCol"]<me["iS_Col"] || 
                                    me["iCol"]+strlen(me["sReplace"]) 
                                    > me["iS_Col"]+79) 
                                        _refresh_screen(pl, me["iS_Row"], 
                                                me["iE_Row"], me["iCol"]); 
                                // ����Ư�Ƶ��滻�ִ����� 
                                me["iCol"] = me["iCol"]+strlen(me["sReplace"])- 
                                        me["iS_Col"]+1; 
                                printf(ESC "[%d;1f%-80s", me["iRow"]+1, 
                                        me["sText"][me["iS_Row"]+ 
                                        me["iRow"]-2][me["iS_Col"]-1 
                                        ..me["iE_Col"]-1]); 
                        } 
                        // ����Ư�Ƶ���Ѱ�ִ����� 
                        else         
                                me["iCol"] = me["iCol"]+strlen(me["sSearch"])-me["iS_Col"]+1; 
                        _refresh_status(pl); 
                        break; 
                } // if found 
        } // for each row 
        if (i >= sizeof(me["sText"])) 
                _message(pl, "�Ҳ���ָ���ִ���", "_message_done", HIDE); 
        else        get_char("_input", HIDE, pl); // ��ȡ�¸������ִ� 
} // _next_match() 
 
 
private void _page_down(object pl)        // ���¾�һҳ��22 �У� 
{ 
        mapping me=pl->query_temp("me"); 
 
        if (me["iS_Row"]+22 > sizeof(me["sText"])) return; // ����Ƿ����پ��� 
        me["iS_Row"] += 22;        me["iE_Row"] += 22; 
        // ����α����λ���Ƿ񳬹���β 
        if (me["iS_Row"]+me["iRow"]-1 > sizeof(me["sText"])) 
                me["iRow"] = sizeof(me["sText"])-me["iS_Row"]+1; 
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]); 
        // ���α����λ�ó�����β�����ƶ��α굽��β 
        if (me["iS_Col"]+me["iCol"]-1 > sizeof(me["sText"][me["iS_Row"]+ 
                me["iRow"]-2])) 
                _end(pl); 
} // _page_down() 
 
 
private void _page_up(object pl)        // ���Ͼ�һҳ��22 �У� 
{ 
        mapping me=pl->query_temp("me"); 
 
        if (me["iS_Row"] <= 1) return; // ����Ƿ����پ��� 
        me["iS_Row"] -= 22; 
        if (me["iS_Row"] < 1) me["iS_Row"] = 1; // ���ֻ�ܷ�����һ�� 
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]); 
        // ���α����λ�ó�����β�����ƶ��α굽��β 
        if (me["iS_Col"]+me["iCol"]-1 > 
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])) 
            _end(pl); 
} // _page_up() 
 
 
private void _process(object pl)        // ��������ģʽ���ִ����� 
{ 
        int    i, size; 
        string str, rest, *input; 
        mapping me=pl->query_temp("me"); 
 
 
        if (me["is_Modify"]==0 || me["is_NewFile"]==1) 
        { 
                me["is_NewFile"] = 0; 
                me["is_Modify"] = 1; 
                _refresh_status(pl); 
        } 
        if (!me["is_Substituted"] && (strsrch(me["sChar"], "\r")!=-1 || 
            strsrch(me["sChar"], "\n")!=-1)) 
                me["is_Substituted"] = 1; // �趨���������� 
        me["sChar"] = replace_string(me["sChar"], "\t", "        "); 
        me["sChar"] = replace_string(me["sChar"], "\r", "\rENTER\r"); 
        me["sChar"] = replace_string(me["sChar"], "\n", "\rENTER\r"); 
        input = explode(me["sChar"], "\r"); 
 
        size = sizeof(input); 
        for (i=0; i<size; i++)                // һ�δ���һ������ 
        { 
                if (me["is_Substituted"] && input[i] == "ENTER") 
                {        // ������ ENTER ʱ��Ҫ���α�֮��������Ƶ���������� 
                        rest = me["sText"][me["iS_Row"]+ 
                                me["iRow"]-2][me["iS_Col"]+me["iCol"]-2..<1]; 
                        me["sText"][me["iS_Row"]+me["iRow"]-2] = 
                                me["sText"][me["iS_Row"]+ 
                                me["iRow"]-2][0..me["iS_Col"]+me["iCol"]-3]; 
                        _append_line(pl); // ���α���¼�һ���� 
                        // ���е�������ԭ�α�λ����������� 
                        me["sText"][me["iS_Row"]+me["iRow"]-2] = rest; 
                        continue; 
                } 
 
                // �����ִ����� ENTER ʱ, ���� TAB �Ķ�λ 
                if (me["is_Substituted"] && input[i] == "TAB") 
                        input[i] = "        "[0..7-(me["iCol"]-1)%8]; 
                str = me["sText"][me["iS_Row"]+me["iRow"]-2][0..me["iS_Col"]+ 
                        me["iCol"]-3] + input[i] + me["sText"][me["iS_Row"] + 
                        me["iRow"]-2][me["iS_Col"]+ me["iCol"]-2..<1]; 
                me["sText"][me["iS_Row"]+me["iRow"]-2] = str; 
                _right(pl, sizeof(input[i]), 1); 
        } // for 
 
        printf(ESC "[%d;1f%s", me["iRow"]+1, me["sText"][me["iS_Row"]+ 
                me["iRow"]-2][me["iS_Col"]-1..me["iE_Col"]-1]); 
        _refresh_cursor(pl); 
} // _process() 
 
 
protected void _quit(mixed unused, mixed pl) // �뿪�༭�� 
{ 
        mapping me; 
 
        seteuid(geteuid(pl)); 
        me = pl->query_temp("me"); 
        if (me["is_Modify"]) 
                return _message(pl, "�˵����Ѹ��ģ�������Ҫ�浵��y/n)��[n]", 
                        "_confirm_save", ECHO); 
        me["iRow"] = 23; 
        _refresh_cursor(pl);                // �ƶ��α굽����һ�� 
        printf(NOR "\r\n"); 
        // �����ܼ�������ձ��ǿյģ������������ϵļ�¼����Ȼ�ͼ�¼��������� 
        if (sizeof(me["keymap"]) == 0) pl->delete("me_keymap"); 
        else pl->set("me_keymap", me["keymap"]); 
        map_delete(EditedFiles, pl->query_temp("me/sFileName")); 
        pl->delete_temp("me"); // ����༭���õ�����ʱ���� 
} // _quit() 
 
 
private void _refresh(object pl)        // ���»��� 
{ 
        mapping me=pl->query_temp("me"); 
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]); 
} // _refresh() 
 
 
private void _replace(object pl)        // �ִ��滻 
{ 
        _message(pl, "��Ѱ/�滻�ִ�(ֱ�Ӱ�ENTERȡ��,�Կհ׸���):", 
                "_replace_done", ECHO); 
} // _replace() 
 
protected void _replace_done(string str, object pl) // ȡ���滻�ִ� 
{ 
        mapping me=pl->query_temp("me"); 
 
        _refresh_status(pl); 
        if (str != "") 
        {        // ����������ʱ 
                if (sscanf(str, "%s %s", me["sSearch"],        me["sReplace"]) != 2) 
                {        // ֻ��һ���ִ�����ָ��Ϊ��Ѱ�ִ����⼴�õ�ָ���ִ� 
                        me["sSearch"] = str; 
                        me["sReplace"] = ""; 
                } 
                _next_match(pl); 
        } 
        else        get_char("_input", HIDE, pl); // ������ȡ�¸������ִ� 
} // _replace_done() 
 
 
private void _right(object pl, int col, int extra)        // �α�������һ�� 
{ 
        int    acc; 
        mapping me=pl->query_temp("me"); 
 
 
        if (sizeof(me["sText"])==0 || me["iS_Col"]+me["iCol"]-1> 
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-1+extra) 
            return; 
        me["iCol"] += col; 
        if (me["iS_Col"]+me["iCol"]-1 > sizeof(me["sText"][me["iS_Row"]+ 
            me["iRow"]-2])+extra) 
                me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])- 
                        me["iS_Col"]+1+extra; 
        if (me["iCol"] > 80) 
        {        // �α����λ�ò��ڿɼ��Ӵ��ڣ���Ҫ�����ƶ��Ӵ� 
                // ������ 8 ��̫��Ļ�����ֻ���Ƶ���β 
                if (me["iE_Col"]+8 > sizeof(me["sText"][me["iS_Row"]+ 
                    me["iRow"]-2])+1) 
                        acc = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])- 
                                me["iE_Col"]+1; 
                else        acc = 8; 
                me["iCol"] = 80-acc+1;         // �����α����λ�� 
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]+acc); 
                return; 
        } 
        _refresh_status(pl); 
} // _right() 
 
 
private void _search(object pl)                // �ִ���Ѱ 
{ 
        _message(pl, "��������Ѱ�ִ���ֱ�Ӱ� ENTER ȡ��)��", "_search_done", 
                ECHO); 
} // _search() 
 
 
protected void _search_done(string str, object pl) // ȡ����Ѱ�ִ� 
{ 
        mapping me=pl->query_temp("me"); 
 
        _refresh_status(pl); 
        if (str != "") 
        {        // ����������ʱ 
                me["sSearch"] = str;        me["sReplace"] = 0; 
                _next_match(pl); 
        } 
        else        get_char("_input", HIDE, pl); // ������ȡ�¸������ִ� 
} // _search_done() 
 
 
private void _tab(object pl)                 // ����ģʽ�� TAB ���Ķ�λ 
{ 
        mapping me=pl->query_temp("me"); 
        _right(pl, 8-(me["iCol"]-1)%8, 0); 
} // _tab() 
 
 
private void _undef_key(object pl)        // ȡ��ĳ���ܼ����� 
{ 
        _message(pl, "��������ȡ������֮��\�ܼ���ֱ�Ӱ� ENTER ȡ��)��", 
                "_undef_key_done", ECHO); 
} // undef_key() 
 
 
protected void _undef_key_done(string str, object pl) // ȡ��ָ�����ܼ� 
{ 
        mapping me=pl->query_temp("me"); 
        if (str != "")        map_delete(me["keymap"], str); 
        _message_done("", pl); 
} // undef_key_done() 
 
 
private void _up(object pl)                // �α�������һ�� 
{ 
        int  acc; 
        mapping me=pl->query_temp("me"); 
 
 
        if (me["iRow"]==1 && me["iS_Row"]==1)        return; 
        if (--me["iRow"] < 1) 
        {        // �α���λ�ò��ڿɼ��Ӵ��ڣ��������Ӵ� 
                me["iS_Row"]--; 
                me["iE_Row"]=me["iS_Row"]+22; 
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]); 
                me["iRow"] = 1; 
        } 
        // ���α���λ�ó�����β�����Ƶ���β 
        if (me["iS_Col"]+me["iCol"]-1 > sizeof(me["sText"][me["iS_Row"]+ 
            me["iRow"]-2])) 
                me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])- 
                        me["iS_Col"]+(me["is_Command_Mode"]?1:2); 
        // ���������֣���λ�ڵ�һ�� 
        if (me["iCol"]==0 && me["iS_Col"]==1) me["iCol"] = 1; 
        if (me["iCol"] > 0) _refresh_status(pl); 
        else 
        {        // �α���λ�ò��ڿɼ��Ӵ��ڣ��ػ滭�� 
                acc = me["iCol"];        me["iCol"] = 1; 
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 
                        me["iS_Col"]+acc-1); 
        } 
} // _up() 
 
 
private void _write(object pl)                // ȡ�ô��浵������ 
{ 
        _message(pl, "�������µ�����ֱ�Ӱ� ENTER ��ʹ�þɵ���)��", 
                "_write_done", ECHO, 0); 
} // _write() 
 
 
protected void _write_done(string str, object pl, int quit) // ���浵�� 
{ 
        string callback; 
        mapping me=pl->query_temp("me"); 
 
        if (str == "") str = me["sFileName"]; 
        else        // ȡ�õ��� 
                str = resolve_path(pl->query("cwd"), str); 
        if (quit) callback = "_quit"; 
        else callback = "_message_done"; 
        if (write_file(str, implode(me["sText"], "\n")+"\n", 1)) 
        { 
                if (me["is_Modify"]) 
                        log_file(LOGFILE, sprintf("[%s] %s %s %s\n", 
                                ctime(time()), getuid(pl), 
                                me["is_NewFile"]? "+": "*", str)); 
                me["is_Modify"] = me["is_NewFile"] = 0; 
                me["sFileName"] = str; 
                _message(pl, "�浵�ɹ�\��", callback, HIDE); 
        } 
        else 
                _message(pl, "�浵ʧ�ܡ�", callback, HIDE); 
} // write_done()
