// Room: /d/guiyun/shiqiao.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long",@LONG
���ǹ���ׯǰ��ʯ�ţ��������ͽ�ׯ�ˡ���ׯ������ȥ������¥��������
���Ǻô�һ��ׯԺ��
LONG );
	set("exits",([
		"north" : __DIR__"damen",
		"east"  : __DIR__"road4",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east")
	{
		write("ׯǰ��һ�����ݾŹ��������ɵ��һ���\n");
		if ((me->query("family/family_name") == "�һ���" &&
			me->query_skill("qimen-wuxing", 1) > 14) ||
			me->query_skill("qimen-wuxing", 1) > 39)
			write( "������ƽ����������Щ���׵��󷨣����Բ���ϸ�룬�Ų����߳�����\n");
		else {
			me->set_temp("jiugong_dir", "e");
			me->move(__DIR__"jiugong" + (random(9) + 1));
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
