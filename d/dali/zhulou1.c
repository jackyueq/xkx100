//Room: /d/dali/zhulou1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��¥��");
	set("long",@LONG
̨����ϲ���������������Ȼ�ٲ��������Ӵ�ɣ���Ϊ������
Ϊǽ����¥�����൱���¡��²������ֻ���ĸ����Ӽܿյģ��ȿ���
����Ȧ��ҲΪ�˷��ߡ�һ������ͨ���ϲ�ķ��ᡣ
LONG);
	set("objects", ([
	   __DIR__"npc/cow": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "south"   : __DIR__"wuding",
	    "up"      : __DIR__"zhulou2",
	]));
	set("coor/x", -41010);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}