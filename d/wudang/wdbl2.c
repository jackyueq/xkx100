//Room: wdbl2.c �䵱����
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
�㴩����һƬï�ܵİ����У���ɭ���䣬��ʯ��ᾣ�����û�ˡ���
������ľ��ʿ���ڷ�����(chop)������ʱ�ؾ������Ӵ������߷��ܶ�
����
LONG);
	set("objects", ([
		__DIR__"obj/cypress" : 1,
		CLASS_D("wudang")+"/famu" : 1,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"west"     : __DIR__"wdbl",
	]));
	set("coor/x", -2050);
	set("coor/y", -820);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
