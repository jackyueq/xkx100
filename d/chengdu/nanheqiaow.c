// Room: nanheqiaow.c
// Date: Feb.14 1998 by Java
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short","�Ϻ���");
	set("long",@LONG
�����ǳɶ��������Ϻ��š����Ӻ��ϺӼг��������ǻ��������
��֮�����׸�֮�ء���ˮ���±�͸��
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */	    
		"east" : __DIR__"westgate",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8100);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

