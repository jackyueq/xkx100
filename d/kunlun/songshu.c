// Room: /d/kunlun/songshu.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�곤���ͱ��ϵ����������϶��������ܿ�����֮��֮���
�Ŵ��϶�����֮ʱ�������������Բ����ļ£���ͷ�亹�乶��£�һ��
�������ƣ����϶���Ԯ�Ǿ������ܣ���������ס����㵽�˵��£�ʮ
֮�˾�Ҳ��û�г�·��Ψ������ɽ��б�£����������г�ȥ��
LONG	);
	set("exits",([
	]));
	set("no_clean_up", 0);
	set("coor/x", -100030);
	set("coor/y", 20010);
	set("coor/z", 40);
	set("outdoors", "hongmei");
	setup();
}
void init()
{
	add_action("do_pa","pa");
}
int do_pa(string arg)
{
	object me;
	me=this_player();
	if (!(arg||arg=="east"||arg=="west")) return 0;
	if (arg=="east"){
		message("vision",me->name()+"����̫������ĵط���ȥ��\n",environment(me),me);
		write("�������ѩɽб����ȥ��\n");
		me->move(__DIR__"xsxiepo1");
		message("vision",me->name()+"���������˹�����\n",environment(me),me);
		return 1;
	}
	if (arg=="west")
	{
		message("vision",me->name()+"��������ȥ��\n",environment(me),me);
		write("���������������ȥ��\n");
		me->move(__DIR__"xuanya1");
		message("vision",me->name()+"���������˹�����\n",environment(me),me);
		return 1;
	}
	return 1;
}
