// Room: /city/chaguan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ����¥����
���Χ���������������Ų輸�������辰��ľ����������ģ���Ŀ�����
�����̸Ц����ͷ�Ӷ���Ʒ����̸����Ҫ����������ƹʺ�ҥ�ԣ�
�����Ǹ������ڡ���ǽ���ż����ֻ��������޷����档�м�������ź�
÷�������������Ű״ɵʡ��˴��о����ţ���������֮�Ѵ���������¥
���˼������乩����������ã����Ϲ���һ�����ӡ�
LONG );
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"qionghuajie",
		"west"  : __DIR__"shilijie1",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
	"/clone/board/player_b"->foo();
}