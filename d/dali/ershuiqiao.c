//Room: /d/dali/ershuiqiao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ˮ��");
	set("long",@LONG
һ�������ಽ����ʯ�š����ź���ˮ�������¹سǺʹ���ǣ�
�����峺�Ķ�ˮ������ȥ���ű������¹سǵĳ��ţ�����һ·����ʮ
���Ｔ�ɵ�����ǡ�
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"xiaguan",
	    "southeast"  : __DIR__"dalinorth",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41000);
	set("coor/y", -58000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}