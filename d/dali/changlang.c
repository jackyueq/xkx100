//Room: /d/dali/changlang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
���������������ĳ��ȣ����߶��Ǵ�Բ�������ϼ�ɽС��Ӧ�о�
�У��Ե�ʮ��������������һ���������ϱ���һ��СͥԺ��
LONG);
	set("objects",([
	    __DIR__"npc/duanwuwei" : 1,
	]));
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"tingfang",
	    "south"  : __DIR__"tingyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38980);
	set("coor/y", -70000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}