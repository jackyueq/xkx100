// Room: /d/xingxiu/shidao.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ�����Ե�׺���ܵ�С����������������ζ������ٳ嵭����
Χ��������������������������������޵��ӣ����Ҷ����еģ�����С
����������һɽ�������ﲻʱ������Ц��������Ҳ�����˿޽���������
LONG
	);
	set("outdoors","xingxiu");
	set("exits", ([ 
		"east"  : __DIR__"xiaojing",
		"enter" : __DIR__"xiaoyao",
	]));
	set("objects", ([ 
		CLASS_D("xingxiu")+"/caihua" : 1,
	]) );
	set("coor/x", -50200);
	set("coor/y", 20200);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if (dir =="enter" )
	{
		if (present("caihua zi", environment(me)))
		{
			if (!myfam || myfam["family_name"] != "������") 
return notify_fail("�ɻ��ӵ�ס���㣺�ҵ�С椿ɲ��Ǹ�����а�ɵ���׼���ģ�\n");
			if  (me->query("gender")=="����") 
return notify_fail("�ɻ��ӵ�ס���㣬һ����Ц������С��廹����椣�����Ц�ˡ�\n");
			if (!(int)this_player()->query_temp("marks/��"))
return notify_fail("�ɻ��ӵ�ס���㣺ι�����ܸ���˼��˼�ɣ�\n");
		}
		return 1;
	}
	return ::valid_leave(me, dir);
}

