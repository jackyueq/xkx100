//Room: /d/dali/gelucheng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��³��");
	set("long",@LONG
�˳����������������θ����������³�����ݡ��²�������Ĵ�
������ɽ�ش��֣����������Ϊ�����ӹ��ڵ͵�Ҳ���Ƥ���ʺϷ���
ţ�򡣴�ȥ������������ɽ������ƽԭ�����д���
LONG);
	set("objects", ([
	   __DIR__"npc/shanyang": 2,
	   __DIR__"npc/muyangren": 1,
	]));
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "northup"    : __DIR__"shanlin",
	    "south"      : __DIR__"zhenxiong",
	    "east"       : __DIR__"minadian",
	]));
	set("coor/x", -90000);
	set("coor/y", -69980);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}