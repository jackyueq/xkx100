// xiang.c
#include <ansi.h>
inherit ITEM;
int do_chuangli(string arg);

int do_weapon();
object creat_weapon();

void create()
{
	set_name("�ص���", ({ "guandi xiang", "xiang" }) );
	set("gender", "����" );
	set("unit", "��");
	set("value", 1);
	set("kar", random(21));
	set("no_get", 1);
	set("no_put", 1);
	set("no_get_from", 1);
        set("long", 	
"����һ��������ǰ����"HIG"����"HIR"����"NOR"���������ף�������ִ�������
�ص�ҹ�������񡣺����ߣ�����һλ"HIW"���װ���"NOR"���������죬���ǹ�ƽ��
����һ����"BLK"��������"NOR"������"HIC"�������µ�"NOR"�ģ������ܲ��ˡ�\n");
}

void init()
{
	add_action("do_chuangli","chuangli");
	add_action("do_chuangli","kaibang");
}

int do_chuangli(string arg)
{
	string *line, file;
	int i, j;
	object ob, me = this_player();

	if (!arg) return notify_fail("��Ҫ����ʲô��̡��᣿\n");

	file = read_file("/log/PARTY");
	line = explode(file, "\n");
	for(j = 0; j < sizeof(line); j ++)
	{
		if (line[j] == arg)
			return notify_fail(arg+"�Ѿ����ڣ���������Ĵ�����\n");
	}
	if (me->query("age") < 50 && !wizardp(me))
		return notify_fail("�㻹�����أ����봴����᣿\n");
	if (me->query("combat_exp") < 5000000)
		return notify_fail("ƾ����ô�����ͣ����봴����᣿\n");
	if (me->query("party") )
		return notify_fail("�����ڻ���"+me->query("party/party_name")+"���ˡ����˳��������ܴ�����ᡣ\n");
	i = strlen(arg);

	if( (strlen(arg) < 4) || (strlen(arg) > 8 ) )
	{
		write("�Բ��𣬰��ɵ��������ֱ����� 2 �� 4 �������֡�\n");
		return 0;
	}
	while(i--)
	{
		if( arg[i]<=' ' )
		{
			write("�������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(arg[i..<0]) )
		{
			write("�������ֱ����ǡ����ġ���\n");
			return 0;
		}
	}
	i = strlen(arg);
	if ((arg[i-2..i]=="��") || (arg[i-2..i]=="��") || (arg[i-2..i]=="��"))
	{
		if(me->query("kar")-this_object()->query("kar")<11)
		{
			me->set("party/party_name", arg);
			me->set("party/rank", arg[i-2..i]+"��");
			me->set("party/level", 1);
			me->set("party/player", 1);
			me->set("party/enter_time", time());
			seteuid(getuid());
			ob=new("/d/luoyang/obj/yaopai");
			ob->move(me);
message_vision("$N���������㣬���Źص��������ȥ�����Ӵ���"+arg+"��־��
������壬�������ơ��ɹصۻ��ӣ��������ڿ�̳���˺󵱵�
Լ�����ڣ�ͬ�����ġ����в�Ф���࣬���Ұ�棬����֮����
��֮����\n", me);
			message_vision("$N���һ�����ƣ�\n",me);
			message("channel:chat", HIY"��ͨ�桿"HIR+me->query("name")+"��"+NATURE_D->game_time()+"����"+arg+"��\n"NOR,users());
			log_file("PARTY", arg+"\n");
		}
		else return notify_fail("������һ�������紵�����������첻�ǿ����ĻƵ����ա����������ɡ�\n");
	}
	else return notify_fail("�������ֻ���Խ̡���Ž�β��\n");
	return 1;
}

