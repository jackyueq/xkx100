//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "ũ��");
	set("long", @LONG
����������ɽ�е�һƬũ�ɽ������ƶ��Ҳûʲô���ֵģ�����
�˼�����ЩС������������ѳ����Ĵ����ߡ��﹣�ϲ����Ŵ󶹺�
���������������͵��ԵñȽ���������
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"tulu3",
		"south"     : __DIR__"maxipu",
	]));
	set("objects", ([
		__DIR__"npc/cow" : 1,
	]));
	set("outdoors", "jiangling");
	set("coor/x", -1610);
	set("coor/y", -2200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}