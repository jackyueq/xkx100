#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����һ���ƾɵĴ�Ժ��Ժ��ʮ�ֿ��������ݰ��ˡ�����һ���쾮��
����������������
LONG );
	set("exits", ([
		"north" : __DIR__"zhuang5",
		"south" : __DIR__"zhuang3",
	]));
	set("objects", ([
		"/d/shenlong/npc/zhang3": 1,
	]));
	set("outdoors", "huabei");
	set("coor/x", 100);
	set("coor/y", 4710);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}
