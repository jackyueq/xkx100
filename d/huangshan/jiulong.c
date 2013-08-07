// Room: /d/huangshan/jiulong.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
������Դ���춼��������壬Ȼ������¯���޺���������¾��۶�
�£�һ��һ̶�����پ�̶����˵�����ÿ�����֮����ˮ���������
�������ۣ��۶����ۣ�����ǧ����ڣ�����������裬��̬���
LONG
	);
	set("exits", ([ 
		"westdown" : __DIR__"baizhang",
		"eastdown" : __DIR__"kuzhu",
	]));
	set("item_desc", ([
		"����": "������Ȼ�����ޱȣ���ʯ��ͻأ��ƽ����������Ŵ��⣨cliff������climb����ȥ��\n"
	]) );
	set("outdoors", "huangshan");
	setup();
}
void init()
{
	add_action("do_climb","climb");
}
int do_climb(string arg)
{
	object me = this_player();

	if(!arg || arg != "cliff") return 0;
	message_vision("$Nץס������ͻ����ʯ�飬����С����ȥ��\n", me);
	me->start_busy(2);
	call_out("arrive",2,me);
	return 1;
}
int arrive(object me)
{
	if(me)
	{
		message_vision("$Nһʧ�֣����������������\n",me);
		me->receive_wound("qi",100);
	}
	return 1;
}
