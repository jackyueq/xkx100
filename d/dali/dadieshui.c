//Room: /d/dali/dadieshui.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���ˮ�ٲ�");
	set("long",@LONG
��ɽ��С·Խ���꣬����ׯ������Ұ��Լ�����������������
ˮ���ĺ�������ǰ������һƬ�µص�ǰ�ˣ����ֵ�Ѿ�������䣬�Ǿ�
��ĺ����������Ǵ����乵�ﴫ���ġ������ϵ�֮����С·���ٷ�ʯ
��ǰ��
LONG);
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : __DIR__"chahuashan6",
	    "eastdown"   : __DIR__"xiaojing",
	    "southdown"  : __DIR__"qingxi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38000);
	set("coor/y", -70500);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}