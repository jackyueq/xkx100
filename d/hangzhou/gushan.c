// gushan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ɽ");
        set("long", @LONG
ͨ���������ǰ��ӭ��ʯ���Ͽ��С���ɽ������������֡�����
ʰ����ɽ����ƽ̨�������߱��Ƿź�ͤ�����ϱ�����ƽ�����¡�����
��ͨ�������š�
LONG);
        set("exits", ([
            "westup"    : "/d/meizhuang/shijie",
            "east"      : __DIR__"pinghuqiuyue",
            "southup"   : __DIR__"gushanpingtai",
            "northwest" : __DIR__"xilingqiao",
            "northeast" : __DIR__"fangheting",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4100);
	set("coor/y", -1460);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
