// jingcaiban.c

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

// ȫ�ֱ��������������Ѻע����������
mapping *all_biao;
// ȫ�ֱ������˴�ΪĿǰ����
int num;
// ȫ�ֱ������˴�Ϊ���ս��
mapping *end_biao;
int jieguo;

// ��������Ϊ��������
int do_read(string);
int do_post(string);
int do_ya(string);
void enough_rest();
string codetoteam(string arg);
string ordercode(string arg, int arg1);
string upcase(string arg);

string *team = ({
"����͢","����","����ʱ","����¡","�й�","��˹�����", "�¹�","����",
"��϶��","������","����","���޵���","������","�����","�ձ�","����",
"ī����","��������","����","������","������","����˹","ɳ��","���",
"˹��������","���ڼӶ�","ͻ��˹","������","Ӣ����","����","������","�Ϸ�"});
string *code=({
	"AR", "BR", "BE", "CM", "CN", "CR", "DE", "DK",
	"EC", "ES", "FR", "HR", "IE", "IT", "JP", "KP",
	"MX", "NG", "PL", "PT", "PY", "RU", "SA", "SE",
	"SI", "SN", "TN", "TU", "UK", "US", "UY", "ZA"
});

void create()
{
	set_name(HIY"���籭���°�"NOR, ({ "board", "ban"}) );
	set("long", "����һ����¼��ҵľ���Ѻע����İ档
Ѻע��read rules���鿴Ŀǰ��Ͷע�����read ban��\n");
	set("unit", "��");
	set("no_put", 1);
	set("no_get", 1);
//���㲻�����Get
	set_weight(900000000);
	seteuid(getuid());
	restore();
}

void init()
{
	add_action("do_read", "read");
	add_action("do_post", "post");
	add_action("do_ya","ya");
	add_action("do_duijiang","duijiang");
	add_action("do_duijiang","duixian");
}

string query_save_file()
{
// ����һ�������ļ���·��
	return DATA_DIR + "board/fifa2002_b";
}

// �����ע
int do_ya(string arg)
{
	int i;
	string c, t, c1, c2, c3, c4, c5, c6, c7, c8;
	object ob, me = this_player();
	mapping biao;
	
// ��ʾֹͣ��ע������ʦ��do_post()���������
	if(query("end_ya"))
		return notify_fail("��ֹʱ���ѹ����»ظ��硣\n");
// ��ֹ����ͬ��Ѻע��������
	if (query_temp("busy"))
		return notify_fail("�Ժ�........\n");
// �������ָ��
	if(!arg)
		return notify_fail("�����ʽ��ya <���> <���> <�������ƽ�>\n");
	arg=upcase(arg);
	if(sscanf(arg, "%s %s %d", t, c, i) != 3)
		return notify_fail("�����ʽ��ya <���> <���> <�������ƽ�>\n");
// �ų�һЩ�����ܵ�Ѻע����
	if(t != "1" && t != "2" && t != "4" && t != "8")
		return notify_fail("����Ҫ��ѡ��Ͷע���գ�\n");
// ����1gold
	if(i < 1)
		return notify_fail("�����׬����\n");
// ���ޣ��������ɵ���
	if(i > 1000)
	    return notify_fail("Ѻ��̫�࣬������1000��\n");
	if((int)i>me->query("balance")/10000)
// Ǯׯ�Ĵ���Ѻ��Ǯ
		return notify_fail("���ﲻ���ֽ𣡵�Ǯׯ�湻��Ǯ������\n");

// Ѻ�ھ�
	switch ( t )
	{
		case "1":
// ��������ϵĲ���
			if(me->query("fifa2002/1"))
				return notify_fail("��ֻ�ܸ��ھ���һ��ע��\n");
			if(codetoteam(c) == "δ֪����")
				return notify_fail("�ȿ��ù��Ҵ���������\n");
			message_vision("$N���˰������������������Ϊ"HIR+codetoteam(c)+NOR"�����õ��ھ���Ѻ "HIY+chinese_number(i)+NOR" ���ƽ𣡡�\n",me);
// �������������Ѻ�Ľ��
			me->set("fifa2002/1", c);
// Ѻ�Ļƽ���
			me->set("fifa2002/10", i);
// ����һ����¼�����Ѻע���ݵ�ӳ��
			biao = ([
				"id"   : me->query("id"),
				"name" : me->query("name"),
				"type" : 1,
				"code" : c,
				"gold" : i,
			]);
			break;
		case "2":
// ��������ϵĲ���
			if(me->query("fifa2002/2"))
				return notify_fail("��ֻ�ܸ��Ǿ���һ��ע��\n");
			if(codetoteam(c) == "δ֪����")
				return notify_fail("�ȿ��ù��Ҵ���������\n");
			message_vision("$N���˰������������������Ϊ"HIR+codetoteam(c)+NOR"�����õ��Ǿ���Ѻ "HIY+chinese_number(i)+NOR" ���ƽ𣡡�\n",me);
// �������������Ѻ�Ľ��
			me->set("fifa2002/2", c);
// Ѻ�Ļƽ���
			me->set("fifa2002/20", i);
// ����һ����¼�����Ѻע���ݵ�ӳ��
			biao = ([
				"id"   : me->query("id"),
				"name" : me->query("name"),
				"type" : 2,
				"code" : c,
				"gold" : i,
			]);
			break;
		case "4":
// ��������ϵĲ���
			if(me->query("fifa2002/4"))
				return notify_fail("��ֻ�ܸ���ǿ��һ��ע��\n");
			if(sscanf(c, "%s-%s-%s-%s", c1, c2, c3, c4) != 4)
				return notify_fail("���Ҵ��������ʽ��\n");
			if(codetoteam(c1) == "δ֪����")
				return notify_fail("û��"HIR+c1+NOR"����Ҵ��룡\n");
			if(codetoteam(c2) == "δ֪����")
				return notify_fail("û��"HIR+c2+NOR"����Ҵ��룡\n");
			if(codetoteam(c3) == "δ֪����")
				return notify_fail("û��"HIR+c3+NOR"����Ҵ��룡\n");
			if(codetoteam(c4) == "δ֪����")
				return notify_fail("û��"HIR+c4+NOR"����Ҵ��룡\n");
			c=ordercode(c, 4);
			message_vision("$N���˰������������������Ϊ"HIR+codetoteam(c1)+"��"+codetoteam(c2)+"��"+codetoteam(c3)+"��"+codetoteam(c4)+NOR"���ܽ�����ǿ��Ѻ "HIY+chinese_number(i)+NOR" ���ƽ𣡡�\n",me);
// �������������Ѻ�Ľ��
			me->set("fifa2002/4", c);
// Ѻ�Ļƽ���
			me->set("fifa2002/40", i);
// ����һ����¼�����Ѻע���ݵ�ӳ��
			biao = ([
				"id"   : me->query("id"),
				"name" : me->query("name"),
				"type" : 4,
				"code" : c,
				"gold" : i,
			]);
			break;
		case "8":
// ��������ϵĲ���
			if(me->query("fifa2002/8"))
				return notify_fail("��ֻ�ܸ���ǿ��һ��ע��\n");
			if(sscanf(c, "%s-%s-%s-%s-%s-%s-%s-%s", c1, c2, c3, c4, c5, c6, c7, c8) != 8)
				return notify_fail("���Ҵ����ʽ�����\n");
			if(codetoteam(c1) == "δ֪����")
				return notify_fail("û��"HIR+c1+NOR"����Ҵ��룡\n");
			if(codetoteam(c2) == "δ֪����")
				return notify_fail("û��"HIR+c2+NOR"����Ҵ��룡\n");
			if(codetoteam(c3) == "δ֪����")
				return notify_fail("û��"HIR+c3+NOR"����Ҵ��룡\n");
			if(codetoteam(c4) == "δ֪����")
				return notify_fail("û��"HIR+c4+NOR"����Ҵ��룡\n");
			if(codetoteam(c5) == "δ֪����")
				return notify_fail("û��"HIR+c5+NOR"����Ҵ��룡\n");
			if(codetoteam(c6) == "δ֪����")
				return notify_fail("û��"HIR+c6+NOR"����Ҵ��룡\n");
			if(codetoteam(c7) == "δ֪����")
				return notify_fail("û��"HIR+c7+NOR"����Ҵ��룡\n");
			if(codetoteam(c8) == "δ֪����")
				return notify_fail("û��"HIR+c8+NOR"����Ҵ��룡\n");
			c=ordercode(c, 8);
			message_vision("$N���˰������������������Ϊ"HIR+codetoteam(c1)+"��"+codetoteam(c2)+"��"+codetoteam(c3)+"��"+codetoteam(c4)+"��"+codetoteam(c5)+"��"+codetoteam(c6)+"��"+codetoteam(c7)+"��"+codetoteam(c8)+NOR"���ܽ����ǿ��Ѻ "HIY+chinese_number(i)+NOR" ���ƽ𣡡�\n",me);
// �������������Ѻ�Ľ��
			me->set("fifa2002/8", c);
// Ѻ�Ļƽ���
			me->set("fifa2002/80", i);
// ����һ����¼�����Ѻע���ݵ�ӳ��
			biao = ([
				"id"   : me->query("id"),
				"name" : me->query("name"),
				"type" : 8,
				"code" : c,
				"gold" : i,
			]);
			break;
	}
	me->add("balance",-i*10000);
	tell_object(me,"Ǯׯ�Ѿ��۳�����Ѻ�µ�"+chinese_number(i)+"���ƽ���Ⱥ����ɣ�\n");
	if( !pointerp(all_biao) ) all_biao = ({ biao });
	else all_biao += ({ biao });
// ���������ļ���Ӧ��.o�ļ���
	save();
	remove_call_out("enough_rest");
// 1���ȡ��busy
	call_out("enough_rest", 1);
	return 1;
}

// ��ʦר�ã�ȷ�����
int do_post(string arg)
{
	int i;
	string c, c1, c2, c3, c4, c5, c6, c7, c8;
	mapping end;
	object me = this_player();

	if(!wizardp(me)) return 0;
	if(arg=="end")
	{
// ֹͣѺע
		set("end_ya", 1);
		message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ����°濪ʼֹͣ��ע�����ע���������\n"NOR, users());
		save();
		return 1;
	}
// ������ʦָ��
	if(!arg) return notify_fail("�����ʽ��post <���> <���>\n");
	arg=upcase(arg);
	if(sscanf(arg, "%d %s", i, c) != 2 )
		return notify_fail("�����ʽ��post <���> <���>\n");
	switch ( i )
	{
		case 1:
			message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ����°�ھ������������ "HIY+codetoteam(c)+HIR" ��Ѻ�ԵĿ�ȥ�ҽ�����\n"NOR, users());
			break;
		case 2:
			message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ����°��Ǿ������������ "HIY+codetoteam(c)+HIR" ��Ѻ�ԵĿ�ȥ�ҽ�����\n"NOR, users());
			break;
		case 4:
			c=ordercode(c, 4);
			if(sscanf(c, "%s-%s-%s-%s", c1, c2, c3, c4) != 4)
				return notify_fail("���Ҵ��������ʽ��\n");
			if(codetoteam(c1) == "δ֪����")
				return notify_fail("û��"HIR+c1+NOR"����Ҵ��룡\n");
			if(codetoteam(c2) == "δ֪����")
				return notify_fail("û��"HIR+c2+NOR"����Ҵ��룡\n");
			if(codetoteam(c3) == "δ֪����")
				return notify_fail("û��"HIR+c3+NOR"����Ҵ��룡\n");
			if(codetoteam(c4) == "δ֪����")
				return notify_fail("û��"HIR+c4+NOR"����Ҵ��룡\n");
			message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ����°���ǿ����������� "HIY+codetoteam(c1)+"��"+codetoteam(c2)+"��"+codetoteam(c3)+"��"+codetoteam(c4)+HIR" ��Ѻ�ԵĿ�ȥ�ҽ�����\n"NOR, users());
			break;
		case 8: 
			c=ordercode(c, 8);
			if(sscanf(c, "%s-%s-%s-%s-%s-%s-%s-%s", c1, c2, c3, c4, c5, c6, c7, c8) != 8)
				return notify_fail("���Ҵ����ʽ�����\n");
			if(codetoteam(c1) == "δ֪����")
				return notify_fail("û��"HIR+c1+NOR"����Ҵ��룡\n");
			if(codetoteam(c2) == "δ֪����")
				return notify_fail("û��"HIR+c2+NOR"����Ҵ��룡\n");
			if(codetoteam(c3) == "δ֪����")
				return notify_fail("û��"HIR+c3+NOR"����Ҵ��룡\n");
			if(codetoteam(c4) == "δ֪����")
				return notify_fail("û��"HIR+c4+NOR"����Ҵ��룡\n");
			if(codetoteam(c5) == "δ֪����")
				return notify_fail("û��"HIR+c5+NOR"����Ҵ��룡\n");
			if(codetoteam(c6) == "δ֪����")
				return notify_fail("û��"HIR+c6+NOR"����Ҵ��룡\n");
			if(codetoteam(c7) == "δ֪����")
				return notify_fail("û��"HIR+c7+NOR"����Ҵ��룡\n");
			if(codetoteam(c8) == "δ֪����")
				return notify_fail("û��"HIR+c8+NOR"����Ҵ��룡\n");
			message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ����°��ǿ����������� "HIY+codetoteam(c1)+"��"+codetoteam(c2)+"��"+codetoteam(c3)+"��"+codetoteam(c4)+"��"+codetoteam(c5)+"��"+codetoteam(c6)+"��"+codetoteam(c7)+"��"+codetoteam(c8)+HIR" ��Ѻ�ԵĿ�ȥ�ҽ�����\n"NOR, users());
			break;
		default : return notify_fail(HIR"����������\n"NOR);
	}
// ����һ����¼������ݵ�ӳ��
	end = ([
		"type" : i,
		"code" : c,
	]);
// ���ս�����������ļ���Ӧ��.o�ļ���
	if( !pointerp(end_biao) ) end_biao = ({ end });
	else end_biao += ({ end });
	jieguo = 1;
	save();
// ����
	return 1;
}
// ��Ҳ鿴
int do_read(string arg)
{
	int i, j;
	object me = this_player();
	string name, str, str1, str2;
	mapping biao;
	
	if(arg == "rules")
	{
//����������ÿ����ʦ��ƵĶ�
		write("
    ���籭�Ĺھ����Ǿ�����ǿ����ǿ�ֱ�˭������ӭ�ڴ�Ѻע��
Ѻע���Իƽ�Ϊ��λ����߿�Ѻһǧ�ƽ�����ҲҪѺһ���ƽ��ֽ�
���գ������ȴ��Ǯׯ��Ѻ�ĺ�Ǯׯֱ�ӿ�Ǯ��Ѻ��ʱ�䵽����ʮ�ս�
ֹ��Ѻ�԰�ǿ��һ���ʮ����ǿ��һ��ʮ�����Ǿ���һ��ˣ�����������
Ѻ���߰����������ƽ𣬲�������ա�
    ����˺�� "HIR"ya <���> <�������> <�������ƽ�> "NOR"��
    ���磺
    ��ѹһǧ�ƽ������͢Ϊ�ھ�����ya 1 AR 1000��
    �����Ϊ��ǿ�ǰ���͢���������������¹���������Ѻ��ٻƽ��
������ya 4 AR-BR-DE-FR 500����Ȼ��˳��������ν�ġ�
    ��Ȼÿ��IDֻ��Ѻһ�Σ�Ѻ�������ڣ�\n

��    ��   "HIY"1-�ھ� 2-�Ǿ� 4-��ǿ 8-��ǿ"NOR"
���ұ�ţ�"HIC"
           A�� ����FR    ����DK    ������UY    ���ڼӶ�SN
           B�� �Ϸ�ZA    ������ES  ������PY    ˹��������SI
           C�� ����BR    �й�CN    ������TU    ��˹�����CR
           D�� ����PL    ����US    ����KP      ������PT  
           E�� �¹�DE    ɳ��SA    ������IE    ����¡CM
           F�� ���SE    ����͢AR  Ӣ����UK    ��������NG
           G�� �����IT  ī����MX  ���޵���HR  ��϶��EC
           H�� �ձ�JP    ����˹RU  ����ʱBE    ͻ��˹TN
\n"NOR);
		write("��������ʹ��duixian <���> ָ���Ľ����Զ��������ʻ���\n");
		return 1;
	}
	if(arg == "ban")
	{
//���˷����Ĳ���
		if(num) write( "������������������������������������\n"HIG"���籭��Ͷע���°�  ");
		write(!jieguo ? RED"����Ͷע�У�":HIR"��ʼ�ҽ�(duijiang)�ˣ�");
//��ʾ��û������
		if( !pointerp(end_biao) || !sizeof(end_biao) )
			write(HIY"\n��ʦ��δ�趨�����\n"NOR);
		else
		{
			write(HIY"\n�������\n"NOR);
			for(i=0; i<sizeof(end_biao); i++)
			{
				switch ( (int)end_biao[i]["type"])
				{
					case 1 : write(HIR"\n�ھ� "); break;
					case 2 : write(HIR"\n�Ǿ� "); break;
					case 4 : write(HIR"\n��ǿ "); break;
					case 8 : write(HIR"\n��ǿ "); break;
				}
				for (j=0; j<sizeof(code); j++)
					if (strsrch(end_biao[i]["code"], code[j]) >= 0)
						write(HIY+team[j]+" "NOR);
			}
		}
//��ʾ��û������
		if( !pointerp(all_biao) || !sizeof(all_biao) )
		{
			write(HIG"\n\n��û���˿�ʼͶע��\n");
			return 1;
		}
		write(HIG"\n\n���� "+sizeof(all_biao)+" �����Ͷע��\n"
		HIY"�����         Ͷע��� Ѻ�ƽ���  ��             ������\n"
		HIG"����������������������������������������������������������������������\n"NOR);
		str1 = HIM"�Ѿ��ҹ�������ң�                \n"NOR;
		str2 = HIM"��δ�ҹ�������ң�                \n"NOR;
// all_biaoҲ��ȫ�ֱ��������ļ�ͷ
		for(i=0; i<sizeof(all_biao); i++)
		{
// ȡ��ÿ��Ѻע��ҵ�����
			str = sprintf("%18s ", all_biao[i]["name"]+"("+all_biao[i]["id"]+")");
			switch ( (int)all_biao[i]["type"])
			{
				case 1 : str += HIR"�ھ�"NOR; break;
				case 2 : str += HIR"�Ǿ�"NOR; break;
				case 4 : str += HIR"��ǿ"NOR; break;
				case 8 : str += HIR"��ǿ"NOR; break;
			}
			str += sprintf("%8s", all_biao[i]["gold"]+"�� ");
			for (j=0; j<sizeof(code); j++)
				if (strsrch(all_biao[i]["code"], code[j]) >= 0)
					str += team[j]+" ";
// dui����������ڶҽ������ģ����ʾû�ҽ��ģ�����str2
			if(!(int)all_biao[i]["dui"]) str2 += str+"\n";
// ��dui�����ģ�����str1
			else str1 += str+"\n";
		}
// ��ʾ��Ϣ
		write(str1+"\n"+str2+"\n"NOR);
		return 1;
	}
	else
		write("��Ҫ��ʲô��Ѻע������read rules��Ѻע�����read ban��\n");
	return 1;
}

void enough_rest()
{
	delete_temp("busy");
}
// �ҽ�ָ��
int do_duijiang(string arg)
{
	int i, j, k, item, t;
	string result;
	object ob, me = this_player();
	mapping biao, fifa2002;

// û��jieguo�ͱ�ʾû�п�ʼ�ҽ�
	if(!jieguo) return notify_fail("��δ���ҽ�ʱ�䣡\n");
	if(!query("end_ya")) return notify_fail("��δ���ҽ�ʱ�䣡\n");
	if(query_temp("busy")) return notify_fail("�Ժ�........\n");
	set_temp("busy",1);
	k = 0;
// ����ָ��
	if(!arg) return notify_fail("�����ʽ��duijiang <���>\n");

	switch (arg)
	{
		case "1" : item = 1; t = 8; break;
		case "2" : item = 2; t = 8; break;
		case "4" : item = 4; t = 10; break;
		case "8" : item = 8; t = 20; break;
		default : return notify_fail("û�������Ŀ�ɣ�\n");
	}
	for(i=0; i<sizeof(all_biao); i++)
	{
		if ((int)all_biao[i]["type"] == item &&
			all_biao[i]["id"] == me->query("id"))
		{
			if (all_biao[i]["dui"] )
				return notify_fail("���Ѷҹ�������\n");
			result = all_biao[i]["code"];
			j = all_biao[i]["gold"];
// ��ʾ���˶ҹ�����
			all_biao[i]["dui"] = 1;
// ����
			save();
		}
	}
	for(i=0; i<sizeof(end_biao); i++)
	{
		if ((int)end_biao[i]["type"] == item &&
			result == end_biao[i]["code"])
		{
			k = j * t;
		}
	}
	if(k>0)
// �н��͸���
	{
		write("��Ѻ "+j+" ���ƽ𣬰��涨�ý��� "+k+" ���ƽ��ѻ������Ǯׯ�ʻ���\n");
		me->add("balance",k*10000);
 		message("channel:sys", HIM"��ҥ�ԡ�"HIR"ĳ�ˣ�"+me->name()+"�ҽ��õ� "+chinese_number(k)+" ���ƽ�\n"NOR, users());
		return 1;
	}
	else
// û�жԵ�Ҳ�������Ž���
	{
		ob = new("/clone/food/jitui");
		ob->move(me);
		write("��ûѺ�ԣ�����һ����ο��������һ�����Ȱɣ�\n");
		message_vision( HIY"���±���ͷͻȻ�͹�һ�������ˡ��ص���һ���͹��ļ��ȣ����õ���$N�����С�\n"NOR,me);
	}
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);
	return 1;
}
// ���������Ĺ��Ҵ��������ĸ����
string ordercode(string arg, int arg1)
{
	int i, j;
	string nc, nc1, nc2, nc3, nc4, nc5, nc6, nc7, nc8;

	j = 1;
	for (i=0; i<sizeof(code); i++)
		if (strsrch(arg, code[i]) >= 0)
		{
			switch(j)
			{
				case 1 : nc1=code[i]; break;
				case 2 : nc2=code[i]; break;
				case 3 : nc3=code[i]; break;
				case 4 : nc4=code[i]; break;
				case 5 : nc5=code[i]; break;
				case 6 : nc6=code[i]; break;
				case 7 : nc7=code[i]; break;
				case 8 : nc8=code[i]; break;
			}
			j ++;
		}
	if(arg1 == 4) nc = nc1+"-"+nc2+"-"+nc3+"-"+nc4;
	if(arg1 == 8) nc = nc1+"-"+nc2+"-"+nc3+"-"+nc4+"-"+nc5+"-"+nc6+"-"+nc7+"-"+nc8;
	return nc;
}
// ���Ҵ����д����
string upcase(string arg)
{
	arg = replace_string(arg, "a","A");
	arg = replace_string(arg, "b","B");
	arg = replace_string(arg, "c","C");
	arg = replace_string(arg, "d","D");
	arg = replace_string(arg, "e","E");
	arg = replace_string(arg, "f","F");
	arg = replace_string(arg, "g","G");
	arg = replace_string(arg, "h","H");
	arg = replace_string(arg, "i","I");
	arg = replace_string(arg, "j","J");
	arg = replace_string(arg, "k","K");
	arg = replace_string(arg, "l","L");
	arg = replace_string(arg, "m","M");
	arg = replace_string(arg, "n","N");
	arg = replace_string(arg, "o","O");
	arg = replace_string(arg, "p","P");
	arg = replace_string(arg, "q","Q");
	arg = replace_string(arg, "r","R");
	arg = replace_string(arg, "s","S");
	arg = replace_string(arg, "t","T");
	arg = replace_string(arg, "u","U");
	arg = replace_string(arg, "v","V");
	arg = replace_string(arg, "w","W");
	arg = replace_string(arg, "x","X");
	arg = replace_string(arg, "y","Y");
	arg = replace_string(arg, "z","Z");
	return arg;
}
// ���Ҵ�������Ĺ������ı任
string codetoteam(string arg)
{
	int i;

	for (i=0; i<sizeof(team); i++)
		if (code[i] == arg)
			return team[i];
	return "δ֪����";

}
