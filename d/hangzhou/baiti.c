// baiti.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�׵�");
        set("long", @LONG
�׵̺ᵩ���ϣ��������ֳ������������������������������ҡ�
ÿ�괺������������˿���̣��������մ�Ц�����׾������С��һ���
�������ۣ�ǳ�ݲ���û���㡣������в��㣬���������ɳ�̡���
����������ľ�ɫ���������߹��˽����ű��ǡ�ƽ�����¡���������
�Ƕ��š�
LONG);
        set("exits", ([
            "southwest" : __DIR__"pinghuqiuyue",
            "east"      : __DIR__"duanqiao",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4130);
	set("coor/y", -1450);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
