//Room: /d/dali/xizhou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ϲ�ݳ�");
	set("long",@LONG
ϲ���������ǣ��Ǵ����ϲ���ǣ����ƴ��Ѽ����٣��ؾ��˻�
���ڣ���ó�����٣��д��������������˽��ף��ɹ�������Ľ�����
˿֯Ʒ��������Ƥë�ȣ�������������ӡ�ȵĿ�����࣬ǰ����˿��
����˹������Զ��������
LONG);
	set("objects", ([
	   __DIR__"npc/keshang": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"tianweijing",
	    "east"       : __DIR__"kedian",
	    "southwest"  : __DIR__"zhulin",
	    "south"      : __DIR__"feilihu",
	]));
	set("coor/x", -40000);
	set("coor/y", -78000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}