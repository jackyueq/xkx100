// /d/xiakedao/shishi24.c ���͵� ʯ��24

inherit ROOM;
#include <ansi.h>

int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������谵��ֻ������������ľ������ϥ���ڽ���֮�ϣ����
ʯ��(wall)�������˼����ʯ������ɽ�������ȴ�����ߴ����
���½����ˡ����л�������������Ķ�����֮�ࡣ
LONG );
        set("exits", ([
                "east" : __DIR__"shihole6",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š�����̫�������������֡��ֵ��·��̵�����������
������ģ���ǧ�������������������룬����������ֱ��б����
�µĴ�Ƭ�������һ���ѷִ���ίʵ���Ա��ϡ�
WALL
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
	set("coor/x", -3100);
	set("coor/y", -25600);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_study","think");
        add_action("do_canwu","canwu");
}
int do_canwu(string arg)
{
	string swith,where;
	object me = this_player();

	if (sscanf(arg,"%s from %s",swith,where)!=2)
  	return notify_fail("ָ���ʽ��yanjiu ���⼼�� from wall\n");

  if (where != "wall") 
    return notify_fail("����û��������������о���\n");

  if (me->is_busy())
    return notify_fail("��������æ���ء�\n");

  if (me->is_fighting())
    return notify_fail("����ս��Ŷ����С�ģ����ˣ�����\n");

  if ((int)me->query_skill("force", 1) < 300)
    return notify_fail("����ڹ���Ϊ�������޷���ͨʯ���ϵľ�ѧ��\n");

  if ((int)me->query("max_neili") < 3000)
    return notify_fail("���������Ϊ���㣬�޷���ͨʯ���ϵľ�ѧ��\n");

  if ((int)me->query("jing") < 100)
    return notify_fail("��ľ����޷����У��޷�����ʯ���ϵľ�ѧ��\n");

  if (me->query_skill("taixuan-gong", 1) < 200)
    return notify_fail("���̫������֪ʵ�����ޣ��޷�����ʯ���ϵľ�ѧ��\n");

    me->receive_damage("jing", 95);

    me->start_busy(2 + random(4));
  if (swith == "taixuan" || swith == "����̫����")
  {
  	if (me->query("can_perform/taixuan-gong/taixuan"))
  	  return notify_fail("�����ѧ�㲻���Ѿ�������\n");
  	if (random(20)==1)
	{
		write(HIM "��Ȼ�䣬��һ����Х�����л�Ȼ��ͨ���������ǡ�\n" NOR);
		write(HIC "������ͨ���˾�ѧ������̫��������\n" NOR);
		me->set("can_perform/taixuan-gong/taixuan",1);
		return 1;
	}
  }
  return notify_fail("����ͼ��ʯ�����о��йء�����̫�����������ݣ���ȴûʲôЧ����\n");
}
int do_study(string arg)
{
	object me, where;
	int jing_cost, learn_pot, item, times, i, success;
	string skillname;

	me = this_player();
	if ( !me->query( "xkd/ling" ) )
		return notify_fail( "δ�����������������Թۿ�ʯ�ڡ�\n" );
	if ( !me->query_temp( "winner" ) )
		return notify_fail( "δ�����������������Թۿ�ʯ�ڡ�\n" );
	if( !arg ) return notify_fail("��Ҫ����ʲô��\n");
	if(  arg != "wall"  )
		return notify_fail("ָ���ʽ��think wall <����>\n");
	if ((int)me->query("combat_exp")<50000)
		return notify_fail("��ľ���̫��, û������ʯ�����ݡ�\n");
	jing_cost = 30 + random(me->query_int());
	if( me->query("jing") < jing_cost || me->query("eff_qi") < 100)
		return notify_fail("������̫���ˣ���������ô��Σ���Ϣһ��������ɡ�\n");
	me->receive_damage("jing",jing_cost);
	if((int)(me->query_skill("taixuan-gong",1) * 
		me->query_skill("taixuan-gong",1) * 
		me->query_skill("taixuan-gong",1)) /10 >= me->query("combat_exp"))
	{
		write("�����ʯ��ڤ˼������һ�ᣬ�����ջ�\n");
		return 1;
	}
	success = 0;
	if (me->query_skill("taixuan-gong",1)<10)
	{
		if (random(20)==1)
		success = 1;
	}
	else if (me->query_skill("taixuan-gong",1)<50)
	{
		if (random(10)==1)
		success = 1;
	}
	else if (me->query_skill("taixuan-gong",1)<100)
	{
		if (random(5)==1)
		success = 1;
	}
	else if (me->query_skill("taixuan-gong",1)<200)
	{
		if (random(3)==1)
		success = 1;
	}
	else 	if (me->query_skill("taixuan-gong",1)>=200)
	{
		write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫ǳ���ˡ�\n");
		return 1;
	}
	learn_pot = (int)(me->query("combat_exp")/10000) + random(me->query("int")) - (int)(me->query_skill("literate",1)/2);
	if (success == 1)
	{
		message_vision(CYN"$N�����ʯ�ڱ�ͷ��˼��ͻȻ�䣬��ͬ����һ��εض���ԭ����Ȼ������̫���񹦵�һЩ���裡\n"NOR,me);
		me->improve_skill("taixuan-gong", learn_pot);
	}
	else
	{
		message_vision(HIR"$N�����ʯ�ڱ�ͷ��˼��ͻȻ�䣬��ͬ����һ��εض��𣬲���һͷײ����ʯ���ϣ�\n"NOR,me);
		me->receive_wound("jing",10);
	}
	return 1;
}
