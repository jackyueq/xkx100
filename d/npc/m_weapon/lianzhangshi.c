// ROOM lianzhangshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "�ȳ�");
	set("long", @LONG
�����������Ŷ������ȵĵط������ܵ�Ҳ����ʮ�ֻ������෴����
˵�м��־��¡�¶�����һ���޴��¯�ӣ�ð����������ף��ƺ�ʲô
���ܱ����ڻ��Ƶġ�
LONG );
	set("exits", ([
		"eastup" : "/d/baituo/xiaolu4",
	]));
	set("objects", ([
		__DIR__"npc/shizhang" :1,
	]));
	set("coor/x", -49970);
	set("coor/y", 20020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
