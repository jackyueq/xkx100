// Room: /d/wuyi/yunwo.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����λ�ڵ�����������Χ������������ˮ�����������������ʯ��
�¡�����ǰ��һ��������ġ�����ʯ����ʯǰΪ�����ѣ�ʯ��Ϊ����
�ѡ���С��Ѩʮ�ദ��ÿ������ʱ�ڣ�һ��һ���Ӷ���ð�����Ƶ���
�����ڷ�ʯ֮������Ʈ����������磬���Ī�⣬�ԹŴ˴���ʽ��ʿ
����Ǳ�����ڡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"   : __DIR__"fuhuyan",
		"north"  : __DIR__"jiesunfeng",
		"south"  : __DIR__"5qu",
		"eastup" : __DIR__"yinpingfeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1360);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

