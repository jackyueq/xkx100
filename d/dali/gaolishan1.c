//Room: /d/dali/gaolishan1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ɽ����");
	set("long",@LONG
�����Ǹ���ɽ�Ķ��£��򶫸��ӱ��ʶ����Ķ���ˮ��ԶԶ������
����Եı���ѩɽ����ȥ������ȫ�ǳ�ɽ���룬����ϡ�١�ɽ������
�޶࣬����������˾�����ɽ���ԡ�
LONG);
	set("objects", ([
	   __DIR__"npc/shanyang": 1,
	]));
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"gaolishan2",
	    "eastdown"  : __DIR__"atoubu",
	]));
	set("coor/x", -90010);
	set("coor/y", -70020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}