// Room: /d/huangshan/shizi.c
// Last Modified by winder on Sep. 27 2001
inherit ROOM;
void create()
{
	set("short", "ʨ�ӷ�");
	set("long", @LONG
Զ����һͷ��ʨ��ͷ��β��������ǰ������ʤ��������ʨ���֣���
�룬���������ɣ����ţ���˵ȹŰض��Ǻ������������������С�û��
ʨ�ӷ壬������ɽ�١���ʢ�������Ա���������̨��Ϊ��������������
�˱�ȥ֮����
LONG
	);
	set("exits", ([ 
		"northdown" : __DIR__"qingliang",
		"southdown" : __DIR__"paiyun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
}
int valid_leave(object me, string dir)
{
	object ob;

	if( userp(me) && dir=="west" &&
		(ob=present("bai hong", this_object()) ||
		ob=present("bai huan", this_object())) &&
		me->query("bellicosity")>50)
		return notify_fail(ob->name()+"˵������������\n");
	return 1;
}
void reset()
{
	object me,me2;

	:: reset();
	me2=present("bai huan", this_object());
	me=present("bai hong", this_object());
	if(me) me->dismiss_team();
	if(me2) me2->dismiss_team();
	if(me && me2) me->add_team_member(me2);
}
