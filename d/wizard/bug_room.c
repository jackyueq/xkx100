// /d/wizard/guest_room.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIC "BUG������" NOR);
	set("long", @LONG
��������ʦ������������bug�ĵط���Ϊ������ʦͳһ��
�����Ҳο���ʦ�����ķ���������ֻ�ܷ���(post)�й���
Ϸbug���⣬�Թ���ʦ�������ҿ����ڴ˷����κη��ϸ�����
�����£���ʦҲ������������ظ�֮��
LONG
);

	set("exits", ([
		"east": __DIR__"guest_room",
]));
	set("no_fight", 1);
	setup();
	"/clone/board/bug_b"->foo();
  replace_program(ROOM);
}