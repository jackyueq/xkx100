// mask.c
//

inherit ITEM;
int query_autoload() {return 1;}

void create()
{
        set_name("���", ({ "mian ju", "mask" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	              set("long", "���ƺ���һ������Ƥ�Ƴɵ���ߡ�\n");
		            set("no_drop", "�������������뿪�㡣\n");
		            set("no_put",1);
		            set("no_get",1);
        }
        setup();
}

void init()
{
	add_action("do_pretend", "pretend");
}

int do_pretend(string arg)
{
	object who;
	string str;
	string pro;
	int per,age;

        if (!present(this_object(), this_player()))
                return 0;

	if (!arg)
		return notify_fail("�����װ˭��\n");
/*
	if (userp(this_player()))
	if (userp(this_player()) && !wizardp(this_player()))
		return notify_fail("ʲô��\n");
*/
	if (arg == "none" || arg == "cancel") {
		this_player()->delete_temp("apply/name");
		this_player()->delete_temp("apply/id");
		this_player()->delete_temp("apply/short");
		this_player()->delete_temp("apply/long");
		this_player()->delete_temp("pretend");
	  this_player()->delete_temp("apply/come_msg");
		message_vision("$N������ȡ����һ����Ƥ��ߡ�\n", this_player());
		return 1;
	}
	if(!objectp(who = present(arg, environment(this_player()))) || 
		!living(who))
		return notify_fail("�����װ˭��\n");
	if(wizardp(who))
	   return notify_fail("�㲻�ܼ�װ��ʦ��\n");
	write("�㿪ʼ��װ" + who->name() + "��\n");
//	message_vision("$N������һ�������Ƴɵ���Ƥ��ߡ�\n", this_player());
	this_player()->set_temp("apply/name", ({who->name()}));
//	this_player()->delete_temp("apply/id");
	this_player()->set_temp("pretend",1);
	this_player()->set_temp("apply/pid", who->parse_command_id_list() );
	this_player()->set_temp("apply/short", ({who->short(1)}));
	this_player()->set_temp("apply/long", ({"/cmds/std/look"->look_living(this_player(),who,1)}));
// for go msg
	if (1)
	{
		object me = who;
		string min,mout;
		string face;
		object thing;
		string dir;
		string thing_msg;
		object env = environment(me);
		
		dir = "����";
	if( me->is_fighting() )
	{
		if( me->query("race") == "����" )
		{
			if (me->query_temp("is_riding") )
			{
				mout = me->name()+"����" + me->query_temp("is_riding")->name() + "������" + dir + "��Ķ����ˡ�\n";	       
				min = me->name()+"����" + me->query_temp("is_riding")->name() + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
			}
			else
			{
				mout = me->name()+"��" + dir + "��Ķ����ˡ�\n";
				min = me->name()+"����ײײ�����˹�����ģ����Щ�Ǳ���\n";
			}
		}
		else {
			mout = me->name()+replace_string( me->query("fleeout_message"), "$d", dir );
			min  = me->name()+me->query("fleein_message");
		}
	} 
	else
	{
			if( me->query("race") == "����" && me->query("age")>15)
			{
				face="��";
				if (me->query("gender")=="Ů��")
				{
					if (me->query("per") >= 30)
						face ="���޾���" + face;
					if ((me->query("per") >= 28) &&
						(me->query("per") < 30))
						face= "��������" + face;
					if ((me->query("per") >= 26) &&
						(me->query("per") < 28))
						face= "��������" + face;
					if ((me->query("per") >= 24) &&
						(me->query("per") < 26))
						face= "��ɫ����" + face;
					if ((me->query("per") >= 21) &&
						(me->query("per") < 24))
						face= "��Ŀ毺�" + face;
					if (me->query("str") <= 16)
						face = "ͤͤ����" + face;
					if ((me->query("str") <= 20) &&
						(me->query("str") > 16))
						face= "��̬��ӯ"+ face;
					if ((me->query("per") < 21) &&
						(me->query("str") > 20) ||
						!userp(me))
						face = "";
				}
				else
				{
					if (me->query("per") >= 30)
						face= "�����ٷ��" + face;
					if ((me->query("per") >= 26) &&
						(me->query("per") < 30))
						face="Ӣ������" + face;
					if ((me->query("per") >= 22) &&
						(me->query("per") < 26))
						face="�Ǳ�����" + face;
					if (me->query("str") >=23)
						face = "���׳˶" + face;
					if ((me->query("str") >= 20) &&
						(me->query("str") < 23))
						face= "�����Բ"+ face;
					if ((me->query("per")<22) &&
						(me->query("str")<20) ||
						!userp(me))
						face = "";
				}
			} else face="";
			if (objectp(thing = me->query_temp("armor/cloth")))
				thing_msg = "����" + thing->query("name");
			else thing_msg = "ȫ���������";
			if (objectp(thing = me->query_temp("weapon")))
				thing_msg += "��ִ" + thing->query("name");
			if( me->query("race") == "����" )
			{
					if( env->query("outdoors") &&
						me->query_temp("is_riding"))
					{
						mout = me->name()+"����"+me->query_temp("is_riding")->name()+"��" + dir + "���۶�ȥ��\n";
						min = face + me->name() + thing_msg + "����"+me->query_temp("is_riding")->name()+"һ·���۶�����\n";
					}
					else
					{
						mout = me->name() + "��" + dir + "�뿪��\n";
						min = face + me->name() + thing_msg + "���˹�����\n";
					}
			}
			else
			{
				mout = me->name()+replace_string( me->query("comeout_message"), "$d", dir );
				min = me->name()+me->query("comein_message");
			}
		}
	this_player()->set_temp("apply/come_msg",min);
	}
// end	
		return 1;
}
void owner_is_killed()
{
	this_player()->delete_temp("apply/come_msg");
	this_player()->delete_temp("apply/name");
	this_player()->delete_temp("pretend");
	this_player()->delete_temp("apply/pid");
	this_player()->delete_temp("apply/short");
	this_player()->delete_temp("apply/long");
        destruct(this_object());
}
