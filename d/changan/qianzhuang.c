// /d/changan/bank.c

#include  <ansi.h>
inherit  ROOM;

void  reset_balance(object  me);

void  create  ()
{
	set  ("short",  "���Ǯׯ");
	set  ("long",  @LONG
����һ�����ֺŵ�Ǯׯ�����ϰ���ɽ���ˣ����Ǯׯ������үү��
үү��үү��үү�Ǳ���ʼ����һֱ��������������ǳ��ã���ȫ
�����ض��зֵꡣ�����е���Ʊ�����ǳ��ã�ͨ��ȫ�����⿴�ϰ彫Ǯ
ׯ���ڱ�Ӫ�Աߣ������ڶ�ʡ�ˣ����֪�����������ë��֮����Ȼ��
���ɲ⡣
    Ǯׯ���ſڣ�����һ������(paizi)��
LONG);
	set("item_desc",  ([
		"paizi":  @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

check             ���ʡ�
deposit           ��
withdraw          ȡ�
convert           �һ�Ǯ�ҡ�

TEXT
	])  );
	set("no_fight", 1);
	set("exits",  ([  //sizeof()  ==  4
	    "east"  :  __DIR__"northroad2",
	]));

	set("objects",  ([  //sizeof()  ==  1
		__DIR__"npc/tiesuanpan"  :  1,
	]));
//		set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5050);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
}
/*
void  init()
{
	reset_balance(this_player());
	::init();
}
*/
void  reset_balance(object  me)
{
	int  myexp=me->query("combat_exp")/1000;
	int  allowed,  removed_gold;
	string  myid=me->query("id");
	string  NPCNAME="������";

	if(myexp<1)  myexp=1;
	if(myexp>100)  myexp=100;
	allowed=myexp*1000000;//each  year  can  have  100  gold,  range  100-10000.  
	if  (me->query("balance")  >  allowed)
	{
	me->set("balance_old",  me->query("balance"));
	me->set("balance",  allowed);
	removed_gold  =  (me->query("balance_old")  -  me->query("balance"))/10000;
	log_file("MONEY_RESET",  ctime(  time()  )+"��κ�����ս���"+me->query("name")+"("+me->query("id")+")"+removed_gold+"���ƽ�\n");
	tell_object(me,  GRN+NPCNAME+"����Ķ�������˵����"+RANK_D->query_respect(me)+
		"���⡢���治֪��ô˵�Ǻã�����\n"NOR);
	tell_object(me,  GRN+NPCNAME+"����Ķ�������˵����"+
		"����κ��������ǰ���참���������ϵĻƽ���·������\n"NOR);
	tell_object(me,  GRN+NPCNAME+"����Ķ�������˵����"+
		"���������°����ϱ�⣬���ϵ�Ǯ��ȫ���乫�ˣ�����\n"NOR);
	}
	return;
}
