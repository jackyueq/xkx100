// Room: /d/henshan/lingxingmen.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
��������������ĵ�һ���ţ��ɺ����񣬻���ʯ��͵�ʯ�Ʒ�����
����ɽ��ף����Ϣ֮�أ����̷�Ϊ����С���졣�ڴ�Զ����ɽ��ɽ����
�ɣ�����������յĴ���
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"north"  : __DIR__"kuixingge",
		"south"  : __DIR__"hengyang",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "henshan");
	set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
