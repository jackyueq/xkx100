//Room: /d/dali/wangfugate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��������");
	set("long",@LONG
����վ��һ�������ĸ���ǰ����ǰ����ֻ�����ʯʨ�ӣ����ϸ�
��һ����ң����顸�����������ĸ����֡��ſ�վ����������������
���£���ִ�ֵ�������������
LONG);
	set("objects", ([
	   CLASS_D("dali")+"/zhuwanli": 1,
	   CLASS_D("dali")+"/first": 1,
	   __DIR__"npc/weishi2": 1,
	   __DIR__"npc/weishi1": 2,
	]));
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : __DIR__"wfdating",
	    "south"  : __DIR__"wangfulu",
	]));
	set("coor/x", -39000);
	set("coor/y", -70990);
	set("coor/z", 0);
	setup();
	"/clone/board/dali_b"->foo();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "����μ�") && dir == "enter" &&
                objectp(present("zhu wanli", environment(me))))
           return notify_fail("��������ס��˵�������˵ȣ��𵽴��Ҵܡ�\n");

        return ::valid_leave(me, dir);
}