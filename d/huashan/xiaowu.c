// Room: /d/huashan/xiaowu.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
������ǻ�ɽ���ڵĵĸ���֮�ء���ʮ�����������ڵ�����н������
ֻ��Ϊ�˶�ػ�ɽ�������ţ�Ϊ�ˣ������˼���������
    ������輫Ϊ��ª����ô������һֱû�г����������ͷʹ�ý���
���������踺�أ�ֻ���ؿ����졣
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"west": __DIR__"pingdi",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/feng-buping": 1,
	]));
	set("valid_startroom","1");

	set("coor/x", -920);
	set("coor/y", 170);
	set("coor/z", 50);
	setup();
	"/clone/board/jianzong_b"->foo();
	replace_program(ROOM);
}
