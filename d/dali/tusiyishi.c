//Room: /d/dali/tusiyishi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
���������������裬���³����ŵ����桢ì��ꪵȱ����������Ĵ�¥��
�£�������ʵ�����ÿ���ǰ�����һ�������������������Ϣ��
LONG);
	set("objects", ([
	   __DIR__"npc/datusi": 1,
	   __DIR__"npc/zutouren": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"tusimentang",
	]));
	set("coor/x", -41000);
	set("coor/y", -71010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}