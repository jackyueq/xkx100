// Room: /d/wuxi/dangpu.c
// Winder 2000/02/22 

inherit ROOM;

int do_quit();
void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ��
��̨�ϰ���һ������ (paizi)����̨�����ŷ��ϰ壬һ˫������������
�´������㡣
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "��ƽ����\n
sell        �� 
buy         ��
value       ����
",
	]));
	set("objects", ([
		__DIR__"npc/feng" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"westroad1",
	]));

	set("coor/x", 360);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
