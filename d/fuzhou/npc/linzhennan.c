// linzhennan.c ������

#include <ansi.h>;

inherit NPC;
inherit F_SKILL;
int ask_fuwei();
int ask_yuantu();
int ask_bixie();
int ask_tong();
int ask_baobiao();

string * destcity = ({
	"����",
	"����",
});
string * destmanager = ({
	"yi biaotou",
	"liu biaotou",
});
void create()
{
	set_name("������", ({ "lin zhennan", "lin", "zhennan" }));
	set("title", HIR"��"HIC"��"YEL"�ھ�"HIY"����ͷ"NOR);
	set("gender", "����");
	set("age", 45);
	set("long", "�����ǡ������ھ֡�������ͷ���������ϡ�\n");

	set("combat_exp", 30000);
	set("shen_type", 1);

	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 10);

	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("bixie-sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	map_skill("parry", "bixie-sword");
	map_skill("sword", "bixie-sword");

	set("inquiry", ([
		"������լ" : "������˵���������Ҵ�ǰ�ڸ���ʱס�ļ�Ժ���Ѿ��ư��ˡ�\n",
		"�����ھ�" : (: ask_fuwei :),
		"Զͼ��" : (: ask_yuantu :),
		"��Զͼ" : "�����ϴ�ŭ��С������ôû��ò��ֱ���������䣡\n",
		"��а����" : (: ask_bixie:),
		"ͭǮ" : (: ask_tong:),
		"ͭ��" : (: ask_tong:),
		"task" : (: ask_baobiao :),
		"����" : (: ask_baobiao :),
		"Ѻ��" : (: ask_baobiao :),
		"����" : (: ask_baobiao :),
	]) );

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
	set("count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_fuwei()
{
 say("��������ҫ��˵�������ּ��������ڣ�һ����������Զͼ�����괳�µ���������\n"
     "�����������ּҼҴ������ն����㺬��������н��յľ��棬��Ϊ����������\n"
     "һָ�Ĵ��ھ֡��������ᵽ�������ھ֡����֣�˭��Ҫ�����Ĵָ��˵һ������\n"
     "�ø����������磡��������������\n");
 this_player()->set_temp("marks/��1", 1);
 return 1;
}

int ask_yuantu()
{
	if ((int)this_player()->query_temp("marks/��1"))
	{
 say("�����Ͽ�һ���̶���˵����Զͼ�����ҵ��游�������ھ�����һ�ִ���ġ�����\n"
     "�游����ʮ��·��а���������ھ֣������Ǵ��ڵ��޵��֡���ʱ�׵���Ӣ�ۼ�\n"
     "��̫�����磬Ҳ��ȥ�����������յģ�����������������ʦ������������֮ʱ\n"
     "��������а���������˼��С�\n");
		this_player()->set_temp("marks/��2", 1);
		return 1;
	}
	else
	{
		say("������˵����Զͼ�����ҵ��游��\n");
		return 1;
	}
}

int ask_bixie()
{
	int p1, p2, p3, p4;

	if ((int)this_player()->query("passwd"))
	{
		say("�����ϲ��õ�˵�����Ҳ��Ƕ������������ҵĽ����������档\n");
	}
	else if ((int)this_player()->query_temp("marks/��2"))
	{
 say("������һ����˵��������ô֪���ģ��ޣ��Ҹղ�˵¶���ˡ��ˣ����µĹ�������\n"
     "��֪��ϸ����ʵ���������档��\n");
		write("�����϶�һ�٣����Ŷ������˵������ȥ��ǰ�������Ҹ�����");
		p1=random(4)+1;
		p2=random(4)+1;
		p3=random(4)+1;
		p4=random(4)+1;
		this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
	write(CHINESE_D->chinese_number(p1)+"ǧ"+CHINESE_D->chinese_number(p2)+
	"��"+CHINESE_D->chinese_number(p3)+"ʮ"+CHINESE_D->chinese_number(p4));
	write("��\nͭǮ����һֱδ�����а��ء�\n");
	}
	else
	{
		message("vision",
	HIY "�����ϲ�Ȼ��ŭ���ȵ�����Ҳ���������ּҵı�а���ף����Ҹ���ƴ�ˣ�\n"
	NOR, environment(), this_object() );
	kill_ob(this_player());
	}
	this_player()->delete_temp("marks/��1");
	this_player()->delete_temp("marks/��2");
	return 1;
}

int ask_tong()
{
	int p, p1, p2, p3, p4;

	if (!(p=(int)this_player()->query("passwd")))
	{
		say("������һ����Ц�����ӣ�˵����ô�쵽��һ���˵���ҪǮ��\n");
	}
	else
	{
	write("�����ϵ���˵������ȥ��ǰ�������Ҹ�����");
	p1=(int)p/1000;
	p2=(int)(p-p1*1000)/100;
	p3=(int)(p-p1*1000-p2*100)/10;
	p4=(int)(p-p1*1000-p2*100-p3*10);
	write(CHINESE_D->chinese_number(p1)+"ǧ"+CHINESE_D->chinese_number(p2)+
	"��"+CHINESE_D->chinese_number(p3)+"ʮ"+CHINESE_D->chinese_number(p4));
	write("��\nͭǮ����һֱδ�����а��ء�\n");
	}
	return 1;
}

int ask_baobiao()
{
	object me = this_player();
	object cart,biaotou,room,fsilver;
	int i;

	if (me->query("age") < 18)
	{
message_vision(HIY"$N�ֶ�$n˵������С���Ӽұ�ʲô�ڣ���\n"NOR,this_object(),me);
		return 1;
	}
	if (me->query("combat_exp") < 10000)
	{
message_vision(HIY"$N�ֶ�$n˵���������ǵ�����Ҳ��Ѻ�ڣ���������ȥ����\n"NOR,this_object(),me);
		return 1;
	}
	i = random(sizeof(destcity));

//	if (!wizardp(me)) return 0;
	if (me->query_temp("fuwei_dest"))
	{
message_vision(HIY"$N��$n˵�������㲻��ȥ��"+me->query_temp("fuwei_dest")+"��ô��������ĥ�䣡��\n"NOR, this_object(), me);
		return 1;
	}
	if (query("count") > 0)
	{
		cart = new(__DIR__"obj/cart");
		cart -> set("guarded",me->query("id"));
		cart -> set("guardby",me->query("name"));
		fsilver = new(__DIR__"obj/fake-silver");
		fsilver->set("name", chinese_number(100000+random(10)*10000)+"��"HIW"����"NOR);
		fsilver->move(cart); 
		biaotou = new(__DIR__"biaotou");
		biaotou -> set("leader_name", me->query("id") );
		if (! room = find_object("/d/fuzhou/biaojudy") )
			room = load_object("/d/fuzhou/biaojudy");
		cart -> move(room);
		biaotou -> move(room);
		add("count",-1);
message_vision(HIY"$N��$n˵���������������ã�������������������"+destcity[i]+"�־֡����ȥ����һ�˰ɣ���\n"NOR, this_object(), me);
message_vision(HIY"$N�ֶ�$n˵����������ȥ�˷�����Ѻ������·����\n"NOR, this_object(), me);
		me->set_temp("fuwei_prepare",1);
		me->delete_temp("fuwei_ready");
		me->set_temp("fuwei_destm",destmanager[i]);
		me->set_temp("fuwei_dest",destcity[i]);
	        call_out("newjob",600,this_object());
		return 1;
	}
	else
	{
		message_vision(HIG"$N��$n˵�����������ò��ɣ������ھֵĻ�����·����\n"NOR, this_object(), me);
		return 1;
	}
}

void newjob()
{
	if (query("count") <= 0) add("count",1);
	remove_call_out("newjob");
	call_out("newjob", 600);
}

