// Room: /d/changcheng/badaling.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�˴���");
	set("long", WHT@LONG
�˴���Ϊ��ӹ����ڣ��سǽ�����ɽ֮�䡣�س��ж��ţ����Ŷ���
����ӹ���򡱣����Ŷ��⡰������Կ�������Ϲ�¥������������ֻ����
ɽ���룬���͵��֣�Ⱥɽ֮��ֻ�а˴���ǹ����ȱ�ڣ����С�һ��
�أ����Ī���������ơ�
LONG
NOR  );
	set("outdoors", "changcheng");
	set("exits", ([
		"west"      :__DIR__"juyongguan",
		"northeast" :__DIR__"beisilou",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
	]));
	set("coor/x", 1000);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}