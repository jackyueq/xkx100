// Room: /guiyun/huayuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ�����͵Ľ���԰�֣���ģ�䲻�󣬹����ȴ��Ϊ���£����
���꽨԰֮�˺ܷ���һ��������԰�л���Ϯ�ˣ�ݺ�����裬������磬
�̲�������ֻ����Ƭ�̱��������崺�磬����������
LONG );
	set("outdoors", "guiyun");
	set("exits", ([
		"east" : __DIR__"zoulang9",
	]));
	set("objects", ([
		__DIR__"npc/xiaoju" : 1,
	]));
	setup();
	replace_program(ROOM);
}
