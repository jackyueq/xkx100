//   feature/bank.c 
#include <ansi.h>
int do_cross();
int do_yell(string arg);
void check_trigger();
void on_board(object boat,string from,string to);
void arrive(object boat,string from,string to);
object find_boat(string from,string to);

#define BOAT "/clone/misc/boat"

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����һ���ӵı��ϣ������������԰�������Ṧ���ã�
Ҳ�����Լ�ʩչ�Ṧ���ӡ�
long
);
	set("yell_about", "����");             // yell ����
	set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("busy_msg",				"ֻ���ý�������������������������æ���š���\n");
  set("come_msg_out",		"һҶ���ۻ�����ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
	set("come_msg_in",		"����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
	set("wait_msg",				"����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n");
	set("leave_msg_out",	"������̤�Ű��������������һ�㣬��������ʻȥ��\n");
	set("leave_msg_in",		"������̤�Ű���������˵��һ��������ඡ������һ�㣬��������ʻȥ��\n");
  set("item_desc/river", HIC "\nֻ����������һҶС�ۣ�Ҳ�������("
                         HIY "yell" HIC ")һ������(" HIY "boat" HIC
                        ")��\n���������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤��������\n" NOR);
	set("boat_short", "�ɴ�");		
	set("boat_desc",  @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳ�
����ݣ����ڴ�β�����س��Ŵ���
LONG);																	 // �ɴ��ϵ�����
	set("from",       file_name(this_object()));      // ���˴������
	set("to",         __DIR__"hanshui2");  // �����յ� /*   ��ѡ   */
	setup();
}

void init()
{
	add_action("do_yell","yell");
	add_action("do_cross","cross");
}

int do_cross()
{
        object me, arrive;
        string msg;
        string go_msg;
        string come_msg;
        int can = 0;
        int need=query("need_dodge");
        string dskill;

        me = this_player();
        arrive = find_object(query("to"));
        if (! arrive)
                arrive = load_object(query("to"));
        if (! arrive)
        {
                tell_object(me, "���Ŀ��ȥ������ˮ��������Ũ��ʲô�������塣\n");
                return 1;
        }
        if (! me->query_skill("dodge", 1))
        {
                tell_object(me, "�����һ�ɣ���ʲô��������ɱô��\n");
                return 1;
        }
        dskill = me->query_skill_mapped("dodge");
        
				if (me->query_skill("king-of-dragon",1) > 0)
        {
        	can = 1;
        	go_msg   = SKILL_D("king-of-dragon")->river_go_msg();
        	come_msg = SKILL_D("king-of-dragon")->river_come_msg();
        }        
        else if (dskill && ( me->query_skill(dskill,1) * (SKILL_D(dskill)->river_point()) >= need ) )
        {
        	can = 1;
        	go_msg   = SKILL_D(dskill)->river_go_msg();
        	come_msg = SKILL_D(dskill)->river_come_msg();
        }
        else if (me->query_skill("dodge",1) >= need )
        {
        	can = 1;
        }        
        if (can != 1) 
        {
        	tell_object(me, "�������һ�£������Լ����Ṧ�ƺ���û�����ҡ�\n");
        	return 1;
        }
        if (me->query("neili") < 300)
        {
                tell_object(me, "���������������������Ϣһ�°ɡ�\n");
                return 1;
        }
        if (!stringp(go_msg))
        	go_msg = HIW "\nֻ��$N" HIW "����΢΢һ�Σ���ȻƮ��������"
                "������ˮ����԰�̤����ȥ��������΢����\n��������"
                  "���������ʵ����������ң���������˾�̾�Ṧ�����"
                 "������û����Ӱ��\n\n" NOR;
        if (!stringp(come_msg))
          come_msg = HIW "\n����ˮ��������ɢ����һ��̤��"
                          "���ˣ�����̤���ӹ�������\n\n" NOR;

        me->add("neili", -200);
        message_vision(go_msg, me);
        me->move(arrive);
        come_msg = replace_string(come_msg,"$N",me->name());
        tell_room(environment(me), come_msg , ({ me }));
        return 1;
}

int do_yell(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="boat" ) arg = query("yell_about");
	if( (int)this_player()->query("age") < 16 )
		message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",this_player());
	else if( (int)this_player()->query("neili") > 500 )
		message_vision("$N���˿�����һ����" + arg +"������������ƽ�͵�ԶԶ���˳�ȥ��\n", this_player());
	else
			message_vision("$N������������Хһ������" + arg + "����\n", this_player());
	if( arg==query("yell_about"))
		check_trigger();
	else
		message_vision(query("river_type")+"����ԶԶ����һ���������" + arg + "��������\n", this_player());
	return 1;
}

void check_trigger()
{
	object boat;

	if(!query("exits/enter") )
	{
		boat = find_boat(query("from"),query("to"));
		if((int)boat->query("yell_trigger")==0 )
		{
				message("vision",query("come_msg_out"), this_object() );
				set("exits/enter", file_name(boat));
				message("vision",query("come_msg_in") , boat);
				boat->set("exits/out", file_name(this_object()));
				boat->set("yell_trigger", 1);
				remove_call_out("on_board");
				call_out("on_board", 15 , boat, file_name(this_object()),query("to"));
		}
		else
			message("vision","ֻ����"+query("river_type")+"������������������������æ���š�����\n",this_object() );
	}
	else 
		message("vision",query("wait_msg"), this_object() );
}

void on_board(object boat,string from,string to) // ��
{
	object from_room;
	int i;
	object *inv;
	
	from_room = find_object(from);
	if( !from_room || !from_room->query("exits/enter") ) return;

	message("vision", query("leave_msg_out"), from_room );
	from_room->delete("exits/enter");

	message("vision",query("leave_msg_in"), boat );
	boat->delete("exits/out");

	inv = all_inventory(boat);
	for (i=0;i<sizeof(inv);i++)
	{
		if (userp(inv[i]))
		{
				remove_call_out("arrive");
				call_out("arrive", 20 ,boat,from,to);
		    return;
		}
	}
	destruct(boat);
}

void arrive(object boat,string from,string to)//����
{
	object to_room;
	if (!to_room = find_object(to))
	 to_room = load_object(to);

	message("vision",query("come_msg_in"),boat );
	boat->set("exits/out", file_name(to_room));

  message("vision",query("come_msg_out"),to_room);
	to_room->set("exits/enter",file_name(boat));

  remove_call_out("on_board");
  call_out("on_board",20,boat,to,from); //����20��� ���յ㷵�����
}

object find_boat(string from,string to)
{
	object boat;
	object *boats;
	int i;
	boats = children(BOAT);
	for(i=0;i<sizeof(boats);i++)
	{
		if (clonep(boats[i]))
		  {
		  	if (stringp(boats[i]->query("from")) &&	boats[i]->query("from")==from) 
		  	{
		  		boat = boats[i];
		  	  return boat;
		  	}
		  	if (stringp(boats[i]->query("to")) && boats[i]->query("to") == from)
		  	{
		  		boat = boats[i];
		  		return boat;
		  	}
		  }
	}
	seteuid(getuid());
	boat = new(BOAT);
	boat->set("from",from);
	boat->set("to"  ,to  );
	boat->set("short",query("boat_short"));
	boat->set("long", query("boat_desc"));
	return boat;
}