// Room: /d/wuxi/road5.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǹٸ�Ϊפ�������뽭��Ҫ�������Ƕ�ר�޵�һ���ٵ�����Ϊ
��Ҫ���ⲻͨ��ʲô�ط����ٵ��ϵ�����ϡ�١�����ȥ�Ǳ��Ŵ��ţ�
����ԶԶ�ؿ��������ŵĳ�¥��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"lianrongqiao",
		"north"  : __DIR__"road6",
	]));
	set("coor/x", 370);
	set("coor/y", -740);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}