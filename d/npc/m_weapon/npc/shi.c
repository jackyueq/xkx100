#include <ansi.h>

void init()
{
	add_action("do_zhu","zhu");
	add_action("do_answer","answer");
}
int do_zhu(string arg)
{
	object me,ob;
	string type ,w_name, id;
	me = this_player();
	ob = this_object();
	type = ob->query("type");
	if(!(me->query_temp("m_make")) ||
	     me->query_temp("m_make") != ob->query("type") ) return 0;

	if((me->query("weapon/make")) )
	{
		message_vision("$Nһ��ãȻ�����Ѿ���һ������������ˣ�������ʲô���ѵ�������ô��\n",ob);
		return 2;
	}
	if( !arg )
		return notify_fail(ob->query("name")+"�����˵��������Ƽ����ź��ٶ���˵��\n");

	sscanf(arg ,"%s %s" ,w_name ,id);
	if(!w_name||!id)
		return notify_fail("ʹ��(zhu "+type+"������ Ӣ�Ĵ���)\n");
	if(id == "corpse" || w_name == "corpse")
		return notify_fail("�Ƿ������ֻ�Ӣ�Ĵ��š�\n");
	if (strlen(w_name)>75) return notify_fail("��ѡ�������̫���˰ɡ�\n");
	if (strlen(id) > 20) return notify_fail("��ѡ���Ӣ�Ĵ���̫���˰ɡ�\n");
	w_name = replace_string(w_name, "$BLK$", BLK);
	w_name = replace_string(w_name, "$RED$", RED);
	w_name = replace_string(w_name, "$GRN$", GRN);
	w_name = replace_string(w_name, "$YEL$", YEL);
	w_name = replace_string(w_name, "$BLU$", BLU);
	w_name = replace_string(w_name, "$MAG$", MAG);
	w_name = replace_string(w_name, "$CYN$", CYN);
	w_name = replace_string(w_name, "$WHT$", WHT);
	w_name = replace_string(w_name, "$HIR$", HIR);
	w_name = replace_string(w_name, "$HIG$", HIG);
	w_name = replace_string(w_name, "$HIY$", HIY);
	w_name = replace_string(w_name, "$HIB$", HIB);
	w_name = replace_string(w_name, "$HIM$", HIM);
	w_name = replace_string(w_name, "$HIC$", HIC);
	w_name = replace_string(w_name, "$HIW$", HIW);
	w_name = replace_string(w_name, "$NOR$", NOR);
	w_name = replace_string(w_name, "\\n", "");
	w_name = replace_string(w_name, "$N", "");
	w_name = replace_string(w_name, "$n", "");
	w_name = replace_string(w_name, "\"", "");
	w_name = replace_string(w_name, "\'", "");
	w_name += NOR;
	message_vision("$N˵����׼��Ҫ������ "+w_name+"("+id+")"+" ��"+type+"��\n",ob);
	message_vision("$N˵������׼��������(answer y)��\n",ob);
	me->set_temp("m_check",1);
	me->set_temp("m_w/name",w_name);
	me->set_temp("m_w/id",id);
	return 1;
}
int do_answer(string arg)
{
	object ob=this_object();
	object me=this_player();
	string type = ob->query("type");
	string w_name,id,make_time,o_name;
	object weapon;
	if (!me->query_temp("m_check")) return 0;
	me->delete_temp("m_check");
	if (arg != "y" && arg != "Y") return notify_fail(ob->query("name")+"˵�����ðɣ����ٿ������һ�¡�\n");
// ��ʼ��������
	me->delete_temp("m_make");
	me->delete_temp("get_orc");
	me->delete_temp("or");
	if(me->query_temp("shenmu") ) o_name="ǧ����ľ";
	if(me->query_temp("jinmu") )  o_name="���׽�ĸ";
	if(me->query_temp("hanzhu") ) o_name="��˿����";
	if(me->query_temp("ironstone") ) o_name="������ʯ";
	w_name = me->query_temp("m_w/name");
	id = me->query_temp("m_w/id");
	make_time=NATURE_D->game_time();
	message_vision("$N������һ�ᣬ��$n����˵�˼��仰��$n���˵�ͷ��˵���ðɣ�\n",me,ob);
	message_vision("\n$n�ع���ת������һ���޴�Ļ�¯���Ķ�����ȼ�������ܵĴ��˵����ʼ��\n",me,ob );
	message_vision(BLU "$N˫����סһ���޴���������͵���¯�н�������������"+o_name+"��ȥ��\n" NOR,me);
	message_vision(RED "ֻ�������һ�����죬��ͷ��"+o_name+"ճ����һ��\n" NOR,me );
	message_vision(YEL "$Nֻ��������һ�ȣ������ѪҺ�ƺ���������������\n" NOR,me);
	message_vision(HIM "һ��Ѫ�����������������ԴԴ���ϵ���¯�е�"+o_name+"ӿȥ��\n" NOR,me );
	if( (me->query("qi"))<(me->query("max_qi")) || 
	(me->query("jing"))<(me->query("max_jing")) || 
	(me->query("neili"))<(me->query("max_neili")) )
	{
		message_vision(HIR "ͻȻ$N������Ѫһ��ӿ��һ�������Ӳ������������� \n" NOR, me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision(HIR "ֻ������һ�����죬һ����"+type+"��¯��ٿȻԾ�𡣻���һ������͵���$N��ǰ�ش�������\n" NOR,me );
	message_vision("$n��״��У���"+type+"���ɣ���Ѫ�Լ�����������\n",me,ob);
	message_vision("$Nֻ������ǰһ����һ����ӰѸ���ޱȵĵ�����$N����ǰ��\n",me);
	message_vision("��"+type+"͸�ش�����$n�Һ�һ������Ѫ�������������ǣ�\n",me,ob);
	message_vision(RED "$n����һ�����ȣ������˵��ϣ��Ѿ�����һϢ�ˡ�\n" NOR,me,ob);
	message_vision("��"+type+"�ַ����������ɵ���գ�����һ����ص����ϡ�\n¯�еĻ����ˡ�һ�ҵľ����������Σ�һ���ֹ��ڳ��š�\n",me );

	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",0);

	me->set("weapon/make",1);		//����������ֹ����ı�־
	me->set("weapon/name",w_name );	//����������
	me->set("weapon/id",id);		//�����Ĵ���
	me->set("weapon/lv",1);			//�����ȼ�
	me->set("weapon/or",o_name);		//��¼����ԭ��
	me->set("weapon/value",0);		//��¼�����������еĵ���
	me->set("weapon/type",type);
	me->set("weapon/time",make_time);
	me->set("weapon/killed",0);

	weapon = new("/d/npc/m_weapon/weapon/m_weapon",1); 
	weapon->move(this_player());
	message_vision("$n������ϣ����Ű߰�Ѫ������Щ���ֵľ�"+type+"��˵��\n"+type+"�����ѡ����ɡ�����$n�����񡣡���Ҳ������ˡ�������\n",me ,ob );
	message_vision("$n���ѵ�˵���������������պã��Ҹ����ˡ�����\n",me,ob);
	ob->die();
// �����������
  return 1;
}