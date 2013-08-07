// Room: /city/wudao.c
// Date: Feb.28 1998 by Java
#include <ansi.h>
inherit ROOM;
string look_gaoshi();
string look_pai();
int  clear_title(string arg);
int sort(string arg);
void add_title(object me,string arg);
void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ǳ�������ʦϯ���߾���̨֮�ϣ��������ߣ���ľ��������
����ɽӭˬ�����¿���̨��Χ��ͷ�ܶ������Ϸ���һ��Сľ�� (pai)��
���������һ�ź�ֽ��ʾ(gaoshi)��
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
		"pai"    : (: look_pai :),
	]));
	set("exits", ([
		"down"      : __DIR__"leitai",
	]));
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("coor/x", -20);
	set("coor/y", -30);
	set("coor/z", 20);
	setup();
//	replace_program(ROOM);
}
string look_pai()
{
	return 
"\n
"HIR"(��̨��)start id1 id2  "HIY"----  ��̨��֮��ҿ�ʼ���䡣
"HIR"load     <player id>   "HIY"----  ���������̨��
"HIR"kick     <player id>   "HIY"----  ���������̨��
"HIR"heal     <player id>   "HIY"----  ����̨����һָ���
"HIR"sort id1 id2 id3 ...   "HIY"----  ��������Ҿ�������

"HIG"titles  <player id> a1 "HIY"----  ��������µ�һ���� (20����)��
"HIG"titles  <player id> a2 "HIY"----  ��������µڶ����� (20����)��
"HIG"titles  <player id> b1 "HIY"----  �������������     (exp<1m)��
"HIG"titles  <player id> c1 "HIY"----  �������������  (3m>exp>1m)�� 
"HIG"titles  <player id> d1 "HIY"----  �������������  (5m>exp>3m)��
"HIG"titles  <player id> e1 "HIY"----  ��������µڶ����� (10m>exp>5m)��
"HIG"titles  <player id> f1 "HIY"----  ��������µ�һ���� (exp>10m)��

\n"NOR;
}
string look_gaoshi()
{
	return 
HIG"\n����help biwu�˽�������
\n"NOR;
}
void init()
{
	if(wizardp(this_player()))
	{
		add_action("do_load", "load");
		add_action("do_kick", "kick");
		add_action("do_heal", "heal");
		add_action("do_sort", "sort");
		add_action("do_titles", "titles");
	}
}
int do_sort(string arg)
{
	string *list;
	object *fighter=({});
	object ob;
	int i,j;
	int *exp;
	string *name;
	
	if (!arg) return 0;
	list = explode(arg," ");
	for (i=0,j=0;i<sizeof(list);i++)
	{
		ob=find_player(list[i]);
		if (!objectp(ob))
			ob=NPC_D->create_player(list[i]);
		if (objectp(ob)) 
			fighter += ({ob});
	}
	fighter = sort_array(fighter,(: $1->query("combat_exp") - $2->query("combat_exp") :));
	write("�������£�\n");
	j= sizeof(fighter);
	while(j--)
	{
		write(sprintf("%20s %9d\n",fighter[j]->query("name")+"("+fighter[j]->query("id")+")",fighter[j]->query("combat_exp")));
		if (!objectp(environment(fighter[j])))
		destruct(fighter[j]);
	}
	return 1;
}
int valid_leave(object me, string dir)
{
        if( dir=="down"  )
      {
      		me->set_temp("view_leitai",0);
	        me->set("no_get",1);
	    }
        return ::valid_leave(me, dir);
}

int do_load(string arg)
{
	object ob, me;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: loadup <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"����̨��\n"NOR, me);
	message_vision(HIG"$N˫��һ�ţ��ڿն�������������̨���ϣ����ǽ�磬ʮ��������\n"NOR, ob);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n��ʲô��ѽ�㣬�������ɸ��ҡ�\n"NOR);
	ob -> move("/d/city/leitai");
	ob -> delete_temp("view_leitai");
	ob -> delete("env/combatd");
	message_vision(HIG"$N�ڿ�������̨���ϣ����ǽ�磬ʮ��������\n"NOR, ob);
	return 1;
}
int do_kick(string arg)
{
	object ob, me;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: kickdown <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"������̨��\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	message_vision(HIG"ֻ����$N໵�һ��������������̨ȥ�ˡ�\n"NOR, ob);
	tell_object(ob,HIR"\nû�湻��������ȥ������ҡ�\n"NOR);
	ob -> move("/d/city/wudao1");
	ob -> set_temp("view_leitai",1);
	message_vision(HIG"ֻ��$N�������У�һ����ƨ�ɶ����ڵ��ϰ���������\n"NOR, ob);
	return 1;
}
int do_heal(string arg)
{
	object ob, me, obj;

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: heal <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");

	tell_object(me, HIG"��Ϊ"+ob->name()+"�ָ�����״̬��\n"NOR);
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("neili", ob->query("max_neili"));
	ob->clear_condition();
	tell_object(ob,HIR"\nΪ��ָ��˱���״̬�����Գ����ˡ�\n"NOR);
	return 1;
}
int do_titles(string arg)
{
	object obj, me=this_player();
	string dest, topic;
	object ob1,ob2;

	if( !arg || sscanf(arg, "%s %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�ƺţ�\n");
	obj = find_player(dest);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
	switch (topic)
	{
                case "a1": 
                	add_title(obj, "���µ�һ����"); 
                	ob1 = new("/u/biwu/puti-zi");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(100);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "a2": 
                	add_title(obj, "���µڶ�����");
                	ob1 = new("/u/biwu/puti-zi");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(50);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "b1": 
                	add_title(obj, "��������֮�񹦸���"); 
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "c1": 
                	add_title(obj, "��������֮��ѧ��ʦ");
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "d1": 
                	add_title(obj, "��������֮һ���콾");
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "e1": 
                	add_title(obj, "����̩��");
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
                case "f1": 
                	add_title(obj, "��������");
                	ob1 = new("/u/biwu/bing6");
                	ob2 = new("/u/biwu/gold");
                	ob2->set_amount(200);
                	ob1->move(me);
                	ob2->move(me);
                	break;
		default: break;
	}
	message_vision(HIG"$N��"+obj->name()+"��ţ���Ʒ�ѽ��������ϡ�\n"NOR, me);
	tell_object(obj,me->query("name")+"�������ţ���ȴ����Ž�Ʒ��\n");
	return 1;
}
void add_title(object me,string arg)
{
        string title;
        title=arg+clear_title(me->query("title"));
        me->set("title",title);
}
string clear_title(string arg)
{
        if( (strsrch(arg, "���µ�һ����") >= 0) ||
            (strsrch(arg, "���µڶ�����") >= 0) ||
            (strsrch(arg, "��������֮�񹦸���") >= 0) ||
            (strsrch(arg, "��������֮��ѧ��ʦ") >= 0) ||
            (strsrch(arg, "��������֮һ���콾") >= 0) ||
            (strsrch(arg, "����̩��") >= 0) ||
            (strsrch(arg, "��������") >= 0))
                {
                arg = replace_string(arg, "���µ�һ����","");
                arg = replace_string(arg, "���µڶ�����","");
                arg = replace_string(arg, "��������֮�񹦸���","");
                arg = replace_string(arg, "��������֮��ѧ��ʦ","");
                arg = replace_string(arg, "��������֮һ���콾","");
                arg = replace_string(arg, "����̩��","");
                arg = replace_string(arg, "��������","");
        }
        return arg;
}
