//Room: /d/dali/yangcanfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���Ϸ�");
	set("long",@LONG
����һ�������ĸ�����ӣ��˼��²�ȴû��ţ����������ϯ
Χס����һ�����ݣ���������������̣�������һЩɣ�ϡ�һλ����
�������������ʵ�ɣҶι��ɣ�ϡ�
LONG);
	set("objects", ([
	   __DIR__"npc/yangcannu": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"buxiongbu",
	]));
	set("coor/x", -30950);
	set("coor/y", -70640);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}