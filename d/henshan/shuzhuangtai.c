// Room: /d/henshan/shuzhuangtai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ױ̨");
        set("long", @LONG
�ؾ�����һ����Ȫ�羵���������Ȫ���ഫΪ�ϳº������ڴ˱���
ʱ���Ա�ˮ��������ױ���ĵط�����ǰʤ�������գ���ʱҹ�䳣����
�⣬���緱�ǵ�㣬������ө�ҷɣ�ɷ��׳�ۡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "north"   : __DIR__"cangjingdian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1020);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
