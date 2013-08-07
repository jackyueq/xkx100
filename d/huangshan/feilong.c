// Room: /d/huangshan/feilong.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�������������ǰ�������ɽ���ն�����ʲô����ľ�ɫ������
������ʿ��ϲ������̽�ģ������и��������ڴˣ����Ժ����߸�������
�������ڴ��ܹ��õ��Ǵ�˵�е��ر�������ɽ����ʯ�������Ӳݴ�����
˿���������˵ļ��󣬵���˭Ҳ���Ϸ���ϣ������Ҫ��һ�ѡ�
LONG
	);
	set("exits", ([ 
		"southwest" : __DIR__"qingliang",
	]));
	set("outdoors", "huangshan");
	setup();
}
void init()
{
	add_action("do_search", "��");
	add_action("do_search", "search");
	add_action("do_search", "sou");
}
int do_search()
{
	string *names = ({"�����","���Ƶ�","˺������","մ�������"});
	object clo, me = this_player();

	clo = new("/clone/cloth/cloth");
	clo->set("name",names[random(sizeof(names))]+"����");
	message_vision("$N�����ʯ�������Ӳݴ�����ɽ����ͣ����Ѱ�ţ���\n",me);
	if(!me->is_busy())
	{
		tell_object(me,"�㷢����һ��"+clo->name()+"��\n");
		clo->move(me);
	}
	me->start_busy(4);
	return 1;
}
