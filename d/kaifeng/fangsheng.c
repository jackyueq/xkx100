// /kaifeng/fangsheng.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������̨�����¾��Ǵ���ˡ�̨��������һ��С���ӣ������ð�ʯ
Χ�������ˡ����ߵĳر��ϡ������ء�������Ϳ���˺�ɫ�����ڳص�һ
�߿����ֵ���������������ƾ٣���������˰�����£�ȴ��ȥ�ܿ���
����Ӱ������Ǳ���������Ƥ����������������ҹ�ˡ�
LONG);
	set("exits", ([
		"east" : __DIR__"qianshou",
		"westdown" : __DIR__"wroad0",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
