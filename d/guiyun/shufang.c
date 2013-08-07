// Last Modified by winder on Jul. 9 2001
// Room: /d/guiyun/shufang.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
������ׯ��ƽ�ն���ĵط�����������ϣ�����ббǶ��һ������
�� (gua)���������ͷ��䲻̫��ġ�����������Ŀ��ȫ��ʫ�ĵ伮����
�����ϰ������ͭ���������������ǹ�����Ϲ���һ��ˮī��(hua)��
��������һ����齣�һλ��ĸߴ����������������ϡ�
LONG );
	set("exits", ([
		"west" : __DIR__"houting",
	]));
	set("item_desc",([
		"hua" : "
�����滭����һ����������������֮ҹ��ͥ�������ְ����������쳤���������į��
�������½�����һ�״ʣ�
����ҹ���˲�ס��������ǧ���Σ������������������ƽ��С������ģ�������������
  ����Ϊ��������ɽ�����ϣ����̡��������¸����ݣ�֪���٣��Ҷ���˭������
�¿����š�������˲���Ϳѻ�����֡�\n"
	]) );
	set("no_fight", 1);
	set("guacount", 1);

	set("objects", ([
		CLASS_D("taohua")+"/lu" : 1,
		__DIR__"npc/shutong" : 1,
	]));

	setup();
}
void init()
{
	add_action("do_take","take");
}
int do_take(string arg)
{
	object obn, me = this_player();
	int n;

	n = this_player()->query_skill("dodge",1);
	if( !arg || arg != "gua" )
	{
		write("��Ҫ��ʲôѽ��\n");
		return 1;
	}
	message_vision("$N����վ�������һ������ͻȻԾ��\n", me);
	if(n >= 80 && query("guacount") > 0)
	{
		message_vision("ֻ��$N�������ڿ��д��˼���������������ƮƮ��أ����ж���һ�\n", me);
		obn = new("/kungfu/class/taohua/obj/bagua");
		obn->move(me);
		add("guacount",-1);
	}
	else message_vision("$N����һ�������ְ����类�������ˡ�\n", me);
        return 1;
}
