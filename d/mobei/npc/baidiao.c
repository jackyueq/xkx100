// baidiao.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void random_leave();
void create()
{
	set_name("��׵�", ({ "bai diao", "diao"}) );
	set("race", "����");
	set("age", 18);
	set("long", "�����ڴ��ԭ�е�һ�����ݡ�\n");
	set("str", 28);
	set("cor", 24);
	set("combat_exp",180000);
	set("env/wimpy",50);
	set("chat_chance", 6);
	set("chat_msg", ({
		"��׵����Ʋ���������˫���ӹ����ذ��ơ�\n",
		"�Ʋ���һ���������£�������ǰ����һ����⡣\n",
		(:random_leave:),
	}));
	set_temp("apply/attack", 28);
	set_temp("apply/armor", 28);

	setup();
}
void init()
{
	object ob;
	::init();
	ob=present("tu jiu",environment());
	if (!ob) ob=present("hei jiu",environment());
	if (ob)
	{
		set_leader(ob);
		kill_ob(ob);
	}
	add_action("do_kill","kill");
	add_action("do_kill","hit");
	add_action("do_kill","fight");
	return;
}

void random_leave()
{
mapping default_dirs = ([
	"east":         "��",
	"west":         "��",
	"south":        "��",
	"north":        "��",
	"eastup":       "����",
	"westup":       "����",
	"southup":      "�ϱ�",
	"northup":      "����",
	"eastdown":     "����",
	"westdown":     "����",
	"southdown":    "�ϱ�",
	"northdown":    "����",
	"southeast":    "����",
	"southwest":    "����",
	"northeast":    "����",
	"northwest":    "����",
	"up":           "��",
	"down":         "��",
	"out":          "��",
	"enter":        "��",
]);

	mapping exits;
	string *dirs,*where,dir;
	int i;

	if( !mapp(exits = environment()->query("exits")) ) return;
	dirs = keys(exits);
	where=values(exits);
	i=random(sizeof(dirs));
        
	if( !undefinedp(default_dirs[dirs[i]]) ) dir = default_dirs[dirs[i]];
	else dir =dirs[i];
	message_vision("$Nһ�������������"+dir+"��ȥ��\n",this_object());
	move(where[i]);
	tell_room(where[i],"һֻ��׵���˹��������Ʋ���������\n");
	return;
}
void do_kill(string arg)
{
	if (!arg||arg!="bai diao") return;
	random_leave();
	return;
}
