// ROOM lianqiang.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "��ǹ��");
	set("long", @LONG
�����������Ŷ�����ǹ�ĵط����ش����Ʒ峱��֮�������ܶ��ں�
���ĵģ��м����һ���޴��¯�ӣ�ð����������ף������������յ�
ͦ�����ġ�
LONG );
	set("exits", ([
		"west" : "/d/tiezhang/sslin2",
	]));
	set("objects",([
		__DIR__"npc/shiqiang" :1,
	]));
	set("coor/x", -2020);
	set("coor/y", -1880);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
