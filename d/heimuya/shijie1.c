// Room: /d/heimuya/shijie1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ɽ·ͻȻ���ͣ�����ɽ��������м�����һ��խխ��ʯ�ף�������
�˲�����С�
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
		"eastdown" : __DIR__"shandao2",
		"westup"   : __DIR__"shijie2",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/fansong" : 1, 
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3230);
	set("coor/y", 4200);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}