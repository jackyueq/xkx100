#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������鷿");
	set("long", @LONG
�����ǿ������鷿�������������������ضѷ��źܶ��顣������
�ϻ���һЩ�ҳ�����Ȼ�Ǻܾ�û�ж����ˡ��������ļ�����������ȴ
���Ե�������͸��������ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"neitang",
	]));
	set("objects", ([
		__DIR__"npc/kang" : 1,
	]));
	set("coor/x", -180);
	set("coor/y", 4084);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
