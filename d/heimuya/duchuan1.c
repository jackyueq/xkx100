// Room: /d/heimuya/duchuang1.c
// Last Modified by winder on Apr. 10 2000

inherit ROOM;
int arrive(object me,int i);

void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ�һ�ξ������ߡ��˸��ˡ�һ����ʮ�������½�ͽװ���
�����ֳֳ���ݣ����ڴ�β���Ŵ����������������ˣ�С�������Ĳٿ�
֮�£�һ֧����ɿ������԰���
LONG );
	set("no_clean_up", 0);
	set("outdoors", "heimuya");
	set("coor/x", -3100);
	set("coor/y", 4040);
	set("coor/z", -10);
	setup();
}
void init()
{
	object me = this_player();
	if (me->query("family/master_id")=="dongfang bubai")
	{
		message_vision("���ڼ���$N�������µ��ӣ�˿�����ҵ����������𺽡�\n",me);
		arrive(me,1);
	}
	else
	call_out("arrive", 5, this_player(),0);
}

int arrive(object me,int i)
{
	message_vision("���ڷ���������������ɣ�Ƭ�̾Ͱ�$N�͵��˱˰���\n", me);
	if (intp(i) && i==1)
	{
		if(me->query_temp("hmy_ship/ct")) me->move(__DIR__"xingxingtan",1);
		else me->move(__DIR__"changtan",1);
	}
	else
	{
		if(me->query_temp("hmy_ship/ct")) me->move(__DIR__"xingxingtan");
		else me->move(__DIR__"changtan");
	}
	me->delete_temp("hmy_ship");
}
