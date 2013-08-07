// /d/npc/m_weapon/weapon/m_axe.c
// Modified by Zeratul Jan 13 2001 ���ܶ����ڵ��ϵ���������

#include <ansi.h>;
#include <weapon.h>;
inherit M_WEAPON; 

int do_hui(object weapon);
string QI,JI,upmsg;
string creat_info(object me,string msg1,int flag);
int do_setwmsg(string arg);
string query_autoload() { return 1 + ""; }	//autoload weapon
void copyto(object ob);

void init()
{
	if (!query("inited")) 
	{
		set("inited",1);
	  copyto(this_player());
	}
  if ( !query("desting") && !environment()->is_character() )
  { 
    	set("desting",1);
    	call_out("dest_me",10,this_object());
  };
	add_action("do_duanlian","duanlian");
	add_action("do_hui","hui");
	add_action("do_setwmsg","setwmsg");
}

void copyto(object me)
{
	string w_name,w_id,w_or;
	int w_lv , damage;
	if (!me->query("weapon/make"))
	{
		call_out("destruct",0,this_object());
    return;
  }
  set("inited",1);
//��������
	w_name=me->query("weapon/name");
	w_id = me->query("weapon/id");
	w_or = me->query("weapon/or");
	w_lv = me->query("weapon/lv");
	set_name(w_name, ({w_id}));
	set("owner",me->query("id"));
	set("ownmake",1);
	damage = w_lv *10 + me->query("gift/weapon");
	switch (me->query("weapon/type"))
	{
		case "��":
			set("unit","��");
			set("wield_msg", "$N������һ���������һ��"+w_name+"�����С�\n");
			set("unwield_msg", "$N����"+w_name+"������һ�𣬱��ں������ˡ�\n");			
			init_axe(damage);
			QI="����";
			JI="ָ����";
			upmsg=CYN"��������һ����һ����������$N��"+w_name+CYN"�У������ˣ�\n"NOR;
			break;

		case "��":
			set("unit","��");
			set("wield_msg", "$N������һ�����ͳ���һ��"+w_name+"�������С�\n");
			set("unwield_msg", "$N����"+w_name+"һ�ӣ�գ�ۼ���Ȼ����Ӱ�١�\n");			
			init_staff(damage);
			QI="����";
			JI="���ȶ�";
			upmsg=HIY"��������һ����һ���������$N��"+w_name+HIY"�壬�����ˣ�\n"NOR;
			break;

		case "��":
			set("unit","��");
			set("wield_msg", "$N������һ�飬�γ���һ��"+w_name+"�����С�\n");
			set("unwield_msg", "$N����"+w_name+"ӭ��һ����գ�ۼ���Ȼ����Ӱ�١�\n");
			init_blade(damage);
			QI="����";
			JI="ָ����";
			upmsg=CYN"��������һ����һ����������$N��"+w_name+CYN"�У������ˣ�\n"NOR;
			break;

		case "��":
			set("unit","��");
			set("wield_msg", "$N������һ�����ó���һ��"+w_name+"���������С�\n");
			set("unwield_msg", "$N����"+w_name+"����һ��������գ�ۼ���Ȼ����Ӱ�١�\n");
			init_club(damage);
			QI="����";
			JI="ָ����";
			upmsg=HIY"��������һ�����ƺ�һ��������������"+w_name+HIY"��ӿ��������\n"NOR;
			break;

		case "��":
			set("unit","��");
			set("wield_msg", "$N��������һ����ȡ����һ��"+w_name+"�������С�\n");
			set("unwield_msg","$N����"+w_name+"������һ��գ�ۼ���Ȼ����Ӱ�١�\n");
			init_hammer(damage);
			QI="����";
			JI="ָ����";
			upmsg=HIY"��������һ����һ���������$N��"+w_name+HIY"�壬�����ˣ�\n"NOR;
			break;

		case "��":
			set("unit","��");
			set("wield_msg", "$N��ৡ���һ�����һ��"+w_name+"�������С�\n");
			set("unwield_msg", "$N�����е�"+w_name+"һ�����׹�һ����ת�ۼ�"+w_name+"��Ȼ������Ӱ��\n");
			init_hook(damage + 2);
			QI="����";
			JI="�󹳼�";
			upmsg=HIY"��������һ����һ���������$N��"+w_name+HIY"�������ˣ�\n"NOR;
			break;

		case "ǹ":
			set("unit","��");
			set("wield_msg", "$N������һ�����ͳ���һ��"+w_name+"�������С�\n");
			set("unwield_msg", "$N����"+w_name+"һ�ӣ�գ�ۼ���Ȼ����Ӱ�١�\n");
			init_spear(damage);
			QI="ǹ��";
			JI="��ǹͷ";
			upmsg=HIY"ǹ������һ����һ���������$N��+"+w_name+HIY"�壬�����ˣ�\n"NOR;
			break;

		case "��":
			set("unit","��");
			set("wield_msg", "$N������һ�����ͳ���һ��"+w_name+"�������С�\n");
			set("unwield_msg", "$N����"+w_name+"һ�ӣ�գ�ۼ���Ȼ����Ӱ�١�\n");
			init_stick(damage);
			QI="����";
			JI="�հ���";
			upmsg=HIY"��������һ����һ���������$N��"+w_name+HIY"�壬�����ˣ�\n"NOR;
			break;

		case "��":
			set("unit","��");
			set("wield_msg", "$N������һ���������һ��"+w_name+"�������С�\n");
			set("unwield_msg", "$N����"+w_name+"ӭ��һ����գ�ۼ���Ȼ����Ӱ�١�\n");
			init_sword(damage);
			QI="����";
			JI="ָ����";
			upmsg=HIY"��������һ����һ���������$N��"+w_name+HIY"�壬�����ˣ�\n"NOR;
			break;

		case "��":
			set("unit","��");
				set("wield_msg", "$N������һ����ˢ�Ķ�����һ��"+w_name+"��\n");
				set("unwield_msg","$N����"+w_name+"һ����գ�ۼ�������䲻����Ӱ�١�\n");
			init_whip(damage);
			QI="����";
			JI="�����";
			upmsg=HIY"��������һ����һ���������$N��"+w_name+HIY"�������ˣ�\n"NOR;
			break;
			
		default :
			tell_object(me,"������������д�����֪ͨ��ʦ�����\n");
			call_out("destruct",0,this_object());
			return;
	}
	switch(w_or)
	{
		//��ͨ�������� 5000
		//������ʼӲ��rigidity ��== �˺�/4 ����������һ��������
		case "ǧ����ľ" :
			set_weight(2000);
      			add("rigidity",query("rigidity")/3);
			set("material", "wood");
			break;
		case "���׽�ĸ" :
			set_weight(30000);
			set("material", "steel");
			break;
		case "��˿����" :
			set_weight(30);
      			set("material","softsteel");
			break;
		case "������ʯ" :
			set_weight(10000);
			add("rigidity",query("rigidity")/2);
			set("material", "iron");
			break;
/*		case "�׻𺮾�" :
			set_weight(30000);
			set("material", "golden");  //������
*/
		default :
	} 
	set_desc(w_lv,w_or,w_name);
	if( me->query("weapon/wield_msg"))
		set("wield_msg", me->query("weapon/wield_msg")+"\n");
	if( me->query("weapon/unwield_msg"))
		set("unwield_msg", me->query("weapon/unwield_msg")+"\n");
  if( me->query("weapon/killed"))
    set("killed", me->query("weapon/killed"));
}

void create()
{	
	set_name("��������",({"own weapon"}));
	set("no_get",(: this_player()->query("id") != this_object()->query("owner") :));
	set("no_drop",1);
	set("player",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("unit","��");
	setup();
}	

int do_duanlian(object weapon)
{
	object me = this_player();
	int w_zhi, w_level;
	string w_name, w_or;

	w_name=me->query("weapon/name");
	w_level = (int)me->query("weapon/lv");

	if (me->query("max_neili") < 100 )
		return notify_fail("��������Ϊ�������޷�����������\n");
	if (me->is_busy()) return notify_fail("��������æ���ء�\n");

	if ( me->is_fighter()) return notify_fail("ս�����޷�������\n");

	if( !weapon || !present( weapon, me ) || query("owner")!=me->query("id"))
		return notify_fail("��Ҫ����ʲô��\n");

	if( (int)me->query("neili") < 10 )
		return notify_fail("��������������޷�����"+QI+"��\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�����"+QI+"��\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�����"+QI+"��\n");

	if( (int)me->query("jing") < 30 )
			return notify_fail("�����ڵľ����޷����У����ܶ���"+QI+"��\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("���Ǳ�ܲ������޷�����"+QI+"��\n");
		
//	if( w_level >= (int)(me->query("int") + me->query("sta"))/2 )
	if(w_level>=(me->query_con()+me->query_sta())/3
//		||w_level>=60  	//����600�˺�  
		)
	{
		message_vision(RED"$Nʹ��������"+w_name+RED"�����Ǻ���ûʲôЧ����\n"NOR, me);
		return 1;
	}
	message_vision(HIR "$N��"+JI+"��һ������˿˿�Ĵ��˽�ȥ��\n" NOR, me);

//	me->start_busy(3);
	me->add("max_neili",-10);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("learned_points", 2);

	w_zhi = (int)me->query("weapon/value");
	w_zhi++;
	me->set("weapon/value", w_zhi);
	w_or = (string)me->query("weapon/or");
	
	if( w_zhi >= ((w_level + 1) * (w_level + 1)))
	{
		w_level++;
		me->set("weapon/lv", w_level);
		message_vision(upmsg,me);
		message_vision(HIG"$N��"+w_name+HIG"�ĵȼ�����ˣ�\n"NOR, me);
//		weapon=this_object();
//		if(weapon->query("equipped") ) 
//			weapon->unequip();
//		reload_object( weapon );
//		weapon->copyto(me);
		seteuid(getuid());
		weapon=new("/d/npc/m_weapon/weapon/m_weapon");
//		weapon->copyto(me);
		weapon->move(this_player());
		me->set("weapon/value",0);
		destruct(this_object());
		return 1;
	}
	message_vision(RED"$N��"+w_name+RED"���ʵظ����ˣ�\n"NOR, me);
	return 1;
}

int do_hui(string weapon)
{	
	string w_name;
	object me,ob;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon || !id(weapon)|| query("owner")!=me->query("id"))
		return 0;
//		return notify_fail("��Ҫ�ݻ�ʲô��\n");
	message_vision(HIR"$N���һ����һ����"+me->query("weapon/type")+"��һ���������¡������¡һ������"+w_name+HIR"��Ϊ���أ�\n"NOR,me);
	me->set("weapon/make",0);
//	me->delete("weapon");
	me->save();
	destruct( this_object() );
	return 1;
}

void owner_is_killed()
{
	object piece;
	write(HIY"ֻ��һ������������"+query("name")+HIY"���ڵ��ϣ��ϳ����ء�\n"NOR);
	this_object()->unequip();
 	seteuid(getuid());
 	piece = new("/clone/misc/piece");
 	piece->set("long", query("long"));
 	piece->set_name( query("name") + "����Ƭ", ({query("id"),"piece"}) );
 	if(environment(environment()))
 	  piece->move(environment(environment()));
	destruct(this_object());
}

int do_setwmsg(string info)
{
	int i;
	object me=this_player();
	string msg,command,msg1;
	string *ban_name=({
		"��",		"��",		"����",		"���",		"��ʦ",
		"����",	"����",	"�ش�",
		});
	object weapon;
	if( !info ) return 0;
	if( !(me->query("weapon/make")))
		return notify_fail("��û�����Ƶı�����\n");
	if (strsrch(info, "$N") < 0)
		return notify_fail("������Ҫ��$N��ʾ���Լ���\n");
	if (strsrch(info, "$WEAPON$") < 0)
		return notify_fail("������Ҫ��$WEAPON$��ʾ��ı�����\n");
	for (i=0;i<sizeof(ban_name);i++)
	if (strsrch(info, ban_name[i]) > 0)
		return notify_fail("����������˷Ƿ��ַ���\n");
	weapon = this_object();
	if( !objectp(weapon) || !present(weapon,me)) 
	return notify_fail("��ı����������ߣ�\n");
	sscanf(info ,"%s %s" ,command ,msg1);
	switch(command)
	{
		case "-w":
			msg = creat_info(me,msg1,1);
			me->set("weapon/wield_msg",msg);
			weapon->set("wield_msg",msg+"\n"NOR);
			break;
		case "-u":
			msg = creat_info(me,msg1,1);
			me->set("weapon/unwield_msg",msg);
			weapon->set("unwield_msg",msg+"\n"NOR);
			break;
		default :
			return notify_fail("��������ʧ�ܣ���ѡ������������ϸ��
�������ļ���\n");
	}
	write("Ok.\n");
	return 1;
	}
	
string creat_info(object who,string msg1,int flag)
{
		string w_name,name;
	int w_lv,color;
	w_lv = who->query("weapon/lv");
	w_name = who->query("weapon/name");
	color = (w_lv/10);
	color = w_lv - color*10;
	switch(color){
		case 1:
		case 2:
			name = HIR + w_name + NOR;
			break;
		case 3:
		case 4:
			name = HIG + w_name + NOR;
			break;
		case 5:
		case 6:
			name = HIY + w_name + NOR;
			break;
		case 7:
		case 8:
			name = HIB + w_name + NOR;
			break;
		case 9:
			name = HIM + w_name + NOR;
			break;
		case 0:
			name = HIC + w_name + NOR;
			break;
	}
	if ( flag==2 )
		return name;
	msg1+="$NOR$";
	msg1 = replace_string(msg1, "$WEAPON$",name);
	msg1 = replace_string(msg1, "$BLK$", BLK);
	msg1 = replace_string(msg1, "$RED$", RED);
	msg1 = replace_string(msg1, "$GRN$", GRN);
	msg1 = replace_string(msg1, "$YEL$", YEL);
	msg1 = replace_string(msg1, "$BLU$", BLU);
	msg1 = replace_string(msg1, "$MAG$", MAG);
	msg1 = replace_string(msg1, "$CYN$", CYN);
	msg1 = replace_string(msg1, "$WHT$", WHT);
	msg1 = replace_string(msg1, "$HIR$", HIR);
	msg1 = replace_string(msg1, "$HIG$", HIG);
	msg1 = replace_string(msg1, "$HIY$", HIY);
	msg1 = replace_string(msg1, "$HIB$", HIB);
	msg1 = replace_string(msg1, "$HIM$", HIM);
	msg1 = replace_string(msg1, "$HIC$", HIC);
	msg1 = replace_string(msg1, "$HIW$", HIW);
	msg1 = replace_string(msg1, "$NOR$", NOR);
	if ( flag==1)
		return msg1;
}

void dest_me(object me)
{
	set("desting",0);
	if (!environment(me) || !environment(me)->is_character())
	{
		message_vision("$N����ʧȥ���ԣ����ڻ���һ�ѳ��������š�\n",me);
    destruct(me);
  }
}