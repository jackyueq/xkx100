// yunmen.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ɯ��ƺ���ǻ�ɽʮ���̡�ʮ���̵ľ������ǡ����š��ˡ������
�š��ɾ����������µ�һ��ɽ����ʯ�̡�����֮�ڵ�С��ؾ������ƺ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"shaluo",
		"southup" : __DIR__"qingke",
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -910);
	set("coor/y", 250);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
 
